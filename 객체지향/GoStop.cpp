#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cursor.h>
#include <assert.h>
#include <iostream>
using namespace std;

const int MaxCard = 48;		// 화투패 개수
const int CardGap = 4;		// 카드간 간격
const int Speed = 1000;		// 카드 낼때 속도
const int PromptSpeed = 2000;	// 메세지 출력 속도

// 화투 한장을 표현하는 클래스
struct SCard
{
	char Name[4];

	SCard() { Name[0] = 0; }
	SCard(const char* pName) {
		strcpy(Name, pName);
	}
	
	int GetNumber() const {
		if (isdigit(Name[0])) return Name[0] - '0';
		if (Name[0] == 'J') return 10;	// 장
		if (Name[0] == 'D') return 11;	// 똥
		return 12;	// 비
	};
	int GetKind() const {
		if (strcmp(Name + 1, "광") == 0) return 0;
		else if (strcmp(Name + 1, "십") == 0) return 1;
		else if (strcmp(Name + 1, "오") == 0) return 2;
		else return 3;
	}
	// 카드 출력
	friend ostream& operator <<(ostream& c, const SCard& C) {
		return c << C.Name;
	}
	//두 카드가 같은지 조사
	bool operator ==(const SCard& Other) const {
		return (strcmp(Name, Other.Name) == 0);
	}
	// 두 카드의 대소 비교 (숫자 비교, 광 십 오 피)
	bool operator <(const SCard& Other) const {
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// 화투의 초기 카드 목록
SCard HwaToo[MaxCard] = {
	"1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
	"4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
	"7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
	"J십","J오","J피","J피","D광","D피","D피","D피","B광","B십","B오","B피"
};

// 카드의 집합을 관리하는 클래스
// 게임 규칙이 추가되어 더 복잡한 동작이 필요하다면 이 클래스를 확장
class CCardSet
{
protected:	// 파생 클래스에서 대해서만 액세스 허가
	SCard Card[MaxCard];	// Has A 관계
	int Num;	// 집합에 포함된 카드의 현재 개수
	const int sx, sy;	// 화면상 출력 좌표
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	// 카드 개수 표시
	int GetNum() { return Num; }
	// 배열의 카드 읽음
	SCard GetCard(int idx) { return Card[idx]; }
	// 재초기화
	void Reset() {
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
};

// 카드 삽입
void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0) return;	// 빈 카드는 삽입 거부
	for (i = 0; i < Num; i++) {	// 카드 집합을 순회하며 삽입할 카드보다 큰 최초의 카드를 찾아 이 위치에 삽입
		if (C < Card[i]) break;	
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));	// 유효한 카드는 정렬된 위치에 삽입
	Card[i] = C;
	Num++;
}

// 카드 제거, 해당 카드 리턴
// 카드 내거나, 데크에서 뒤집을때 호출
SCard CCardSet::RemoveCard(int idx) {
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

// 일치하는 카드 조사, 개수를 리턴
int CCardSet::FindSameCard(SCard C, int* pSame) {
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {
			num++;
			*p++ = i;
		}
	}
	*p = -1;	// 끝표시 -1
	return num;
}

// 부분 문자열 검색으로 숫자나 종류가 일치하는 최초의 카드를 검색
// 첨자를 리턴하되 발견되지 않으면 -1을 리턴
// 카드의 존재 여부를 검색
int CCardSet::FindFirstCard(const char* pName) {
	int i;

	for (i = 0; i < Num; i++) {	// 순차 검색
		if (strstr(Card[i].Name, pName) != NULL) {	
			return i;
		}
	}
	return -1;
}

// 담요 중앙에 카드를 쌓아 놓는 데크
class CDeck : public CCardSet	// 카드의 집합이므로 CCardSet을 상속받음(Is A관계)
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
	// 카드를 섞음
	void Shuffle() {
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);	
			} while (Card[n].Name[0] != NULL);	// 빈칸을 찾을때까지 난수 고름
			Card[n] = HwaToo[i];
			Num++;
		}

	}
	// 플레이어한테 나눠주는 동작
	SCard Pop() { return RemoveCard(Num - 1); }
	// 카드가 0인지 조사하여 게임 끝인지 조사
	bool IsEmpty() { return Num == 0; }
	// 마지막판인지 조사
	// 남은 카드가 두장 이상이면 아직 막판이 아님, 한장만 남았으면 막판
	// 마지막 판은 항상 싹쓸이
	bool IsNotLast() { return Num > 1; }
	// 화면에 데크를 그림 -> ???, 뒤집은 카드한장만 출력
	void Draw(bool bFlip) {	// bFlip은 제일 윗장을 뒤집어 보여줄것인가를 지정
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");	
	}
};

// 게임을 하는 플레이어
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	// 플레이어의 패를 그림
	void Draw(bool MyTurn) {
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {	// 내 턴일때는 번호 출력, 아니면 안함
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// 게임이 진행되는 담요
class CBlanket : public CPlayer	// 담요는 일정 개수의 카드를 가지고 정렬 상태로 카드를 표시한다는 면이 플레이어와 유사
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	// 카드를 보여줄뿐 고를 필요가 없어 myturn의 인수는 항상 false
	void Draw() {
		CPlayer::Draw(false);
	}
	// 일치하는 카드가 둘 이상이면 위쪽에 일련번호 출력
	void DrawSelNum(int* pSame) {	// pSame : 일련번호를 표시할 카드의 첨자
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	// 먹을 카드 아래에 낸 카드를 출력해 두카드가 일치함을 보여줌
	void DrawTempCard(int idx, SCard C) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// 플레이어가 먹은 카드의 집합 : 먹은 패와 점수 관리
class CPlayerPae : public CCardSet
{
private:
	int nGo;	// 고 횟수

public:
	int OldScore;	// 점수
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }	// 맞고에서는 7점이상 스톱가능, 빠른진행위해 6점부터
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }	// 재초기화
	int GetGo() { return nGo; }		// private이라서 read함수 생성
	void IncreaseGo() { nGo++; }	// 고는 증가만 가능
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

// 먹은 패를 화면에 보기 좋게 종류별로 출력
void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {	// 광,십,오는 한줄로 출력
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {
			gotoxy(x[3], py);	// 개행 처리를 위해 현재 행을 py에 저장
			x[3] += CardGap;	
			if (x[3] > 75) {	
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";
}

// 상대방이 세장을 한꺼번에 먹거나 싹쓸이 했을때
// 피 한장을 제거하여 상대방에게 상납
SCard CPlayerPae::RemovePee() {
	int idx;

	idx = FindFirstCard("피");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard();	// 상대방이 먹은 패에 삽입
}

// 고스톱 규칙대로 점수 계산
// 광 개수에 따라 세장이상은 각각 3,4,15점
// 비광이 포함된 3광은 2점
// 십과 오는 다섯장부터 1점
// 청단,초단, 홍단은 각 3점
// 고도리 5점
int CPlayerPae::CalcScore() {
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };	// 광 개수에 따라 세장 이상은 3,4,15점으로 계산

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;	// 비광이 포함된 3광은 2점
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;	// 십과 오는 다섯장부터 1점
	return NewScore;
}

// 함수 원형
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// 전역 변수
CDeck Deck(18, 9);		// 데크 배치
CPlayer South(5, 20), North(5, 1);	// 아래 남군, 위 북군
CBlanket Blanket(5, 12);	// 담요
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);	// 먹은 패는 오른쪽에 배치
bool SouthTurn;	// 낼 차례 저장

// 프로그램을 총지휘하는 main 함수
void main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;

	randomize();	// 난수 발생기 초기화
	Initialize();	// 데크에 카드를 섞고 패를 골고루 나누어 게임판 생성
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {	// 남군 차례부터 시작; 데크가 빌때까지 진행;카드 하나 낼때마다 한번 반복
		DrawScreen();	// 각 객체를 화면에 그린다.
		// 차례에 따라 대상 패를 미리 조사해 놓는다.
		if (SouthTurn) {
			Turn = &South;
			TurnPae = &SouthPae;	
			OtherPae = &NorthPae;
		}
		else {
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) {
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)	// 점수 낸 사람이 stop하면 종료
				return;
			else
				continue;
		}

		// 플레이어가 카드를 한장 낸다.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);
		SameNum = Blanket.FindSameCard(UserCard, arSame);
		switch (SameNum) {
		case 0:
			UserSel = -1;
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));
			DrawScreen();
			break;
		case 1:
			UserSel = arSame[0];
			break;
		case 2:
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
			}
			break;
		case 3:
			UserSel = arSame[1];
			UserTriple = true;
			break;
		}
		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard);
		}
		delay(Speed);

		// 데크에서 한장을 뒤집는다.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop();
		SameNum = Blanket.FindSameCard(DeckCard, arSame);
		switch (SameNum) {
		case 0:
			DeckSel = -1;
			break;
		case 1:
			DeckSel = arSame[0];
			if (DeckSel == UserSel) {
				if (Deck.IsNotLast()) {
					Blanket.InsertCard(DeckCard);
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("설사했습니다.", PromptSpeed);
					continue;
				}
				else {
					DeckSel = -1;
				}
			}
			break;
		case 2:
			if (UserSel == arSame[0]) {
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) {
				DeckSel = arSame[0];
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
					DeckSel = arSame[0];
				}
				else {
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:
			DeckSel = arSame[1];
			DeckTriple = true;
			break;
		}
		if (DeckSel != -1) {
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
		if (UserSel != -1) {
			if (UserTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
			if (DeckSel != -1 && DeckSel > UserSel) {
				DeckSel -= (UserTriple ? 3 : 1);
			}
		}
		if (DeckSel != -1) {
			if (DeckTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
			}
			TurnPae->InsertCard(DeckCard);
		}
		else {
			Blanket.InsertCard(DeckCard);
		}

		// 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("싹쓸이입니다.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// 점수를 계산하고 고, 스톱 여부를 질문한다.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {
			DrawScreen();
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
			}
			else {
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("게임이 끝났습니다.", 0);
}

/* 도우미 함수 */
// 데크의 패를 무작위로 섞어 카드를 초기화
void Initialize()
{
	int i;

	Deck.Shuffle();
	for (i = 0; i < 10; i++) { // 플레이어한테 10장씩
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8) Blanket.InsertCard(Deck.Pop());	// 데크에 8장
	}
}

//화면을 지우고 모든 객체의 Draw함수를 차례대로 호출
void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

// 하단에 짧은 메시지를 출력
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);	// 사용자가 메시지를 읽을동안 잠시 기다린다.
}

// 지정한 범위의 정수 하나를 입력받음
// 남은 카드수에 따라 지정한 범위가 가변적
int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(getch());
		if (ch == 0xE0 || ch == 0) {	
			ch = getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';	// A대신 10
		if (ch >= start && ch <= end) {	
			return ch;
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}

