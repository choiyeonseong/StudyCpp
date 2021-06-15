#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cursor.h>
#include <assert.h>
#include <iostream>
using namespace std;

const int MaxCard = 48;		// ȭ���� ����
const int CardGap = 4;		// ī�尣 ����
const int Speed = 1000;		// ī�� ���� �ӵ�
const int PromptSpeed = 2000;	// �޼��� ��� �ӵ�

// ȭ�� ������ ǥ���ϴ� Ŭ����
struct SCard
{
	char Name[4];

	SCard() { Name[0] = 0; }
	SCard(const char* pName) {
		strcpy(Name, pName);
	}
	
	int GetNumber() const {
		if (isdigit(Name[0])) return Name[0] - '0';
		if (Name[0] == 'J') return 10;	// ��
		if (Name[0] == 'D') return 11;	// ��
		return 12;	// ��
	};
	int GetKind() const {
		if (strcmp(Name + 1, "��") == 0) return 0;
		else if (strcmp(Name + 1, "��") == 0) return 1;
		else if (strcmp(Name + 1, "��") == 0) return 2;
		else return 3;
	}
	// ī�� ���
	friend ostream& operator <<(ostream& c, const SCard& C) {
		return c << C.Name;
	}
	//�� ī�尡 ������ ����
	bool operator ==(const SCard& Other) const {
		return (strcmp(Name, Other.Name) == 0);
	}
	// �� ī���� ��� �� (���� ��, �� �� �� ��)
	bool operator <(const SCard& Other) const {
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// ȭ���� �ʱ� ī�� ���
SCard HwaToo[MaxCard] = {
	"1��","1��","1��","1��","2��","2��","2��","2��","3��","3��","3��","3��",
	"4��","4��","4��","4��","5��","5��","5��","5��","6��","6��","6��","6��",
	"7��","7��","7��","7��","8��","8��","8��","8��","9��","9��","9��","9��",
	"J��","J��","J��","J��","D��","D��","D��","D��","B��","B��","B��","B��"
};

// ī���� ������ �����ϴ� Ŭ����
// ���� ��Ģ�� �߰��Ǿ� �� ������ ������ �ʿ��ϴٸ� �� Ŭ������ Ȯ��
class CCardSet
{
protected:	// �Ļ� Ŭ�������� ���ؼ��� �׼��� �㰡
	SCard Card[MaxCard];	// Has A ����
	int Num;	// ���տ� ���Ե� ī���� ���� ����
	const int sx, sy;	// ȭ��� ��� ��ǥ
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	// ī�� ���� ǥ��
	int GetNum() { return Num; }
	// �迭�� ī�� ����
	SCard GetCard(int idx) { return Card[idx]; }
	// ���ʱ�ȭ
	void Reset() {
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
};

// ī�� ����
void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0) return;	// �� ī��� ���� �ź�
	for (i = 0; i < Num; i++) {	// ī�� ������ ��ȸ�ϸ� ������ ī�庸�� ū ������ ī�带 ã�� �� ��ġ�� ����
		if (C < Card[i]) break;	
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));	// ��ȿ�� ī��� ���ĵ� ��ġ�� ����
	Card[i] = C;
	Num++;
}

// ī�� ����, �ش� ī�� ����
// ī�� ���ų�, ��ũ���� �������� ȣ��
SCard CCardSet::RemoveCard(int idx) {
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

// ��ġ�ϴ� ī�� ����, ������ ����
int CCardSet::FindSameCard(SCard C, int* pSame) {
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {
			num++;
			*p++ = i;
		}
	}
	*p = -1;	// ��ǥ�� -1
	return num;
}

// �κ� ���ڿ� �˻����� ���ڳ� ������ ��ġ�ϴ� ������ ī�带 �˻�
// ÷�ڸ� �����ϵ� �߰ߵ��� ������ -1�� ����
// ī���� ���� ���θ� �˻�
int CCardSet::FindFirstCard(const char* pName) {
	int i;

	for (i = 0; i < Num; i++) {	// ���� �˻�
		if (strstr(Card[i].Name, pName) != NULL) {	
			return i;
		}
	}
	return -1;
}

// ��� �߾ӿ� ī�带 �׾� ���� ��ũ
class CDeck : public CCardSet	// ī���� �����̹Ƿ� CCardSet�� ��ӹ���(Is A����)
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
	// ī�带 ����
	void Shuffle() {
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);	
			} while (Card[n].Name[0] != NULL);	// ��ĭ�� ã�������� ���� ��
			Card[n] = HwaToo[i];
			Num++;
		}

	}
	// �÷��̾����� �����ִ� ����
	SCard Pop() { return RemoveCard(Num - 1); }
	// ī�尡 0���� �����Ͽ� ���� ������ ����
	bool IsEmpty() { return Num == 0; }
	// ������������ ����
	// ���� ī�尡 ���� �̻��̸� ���� ������ �ƴ�, ���常 �������� ����
	// ������ ���� �׻� �Ͼ���
	bool IsNotLast() { return Num > 1; }
	// ȭ�鿡 ��ũ�� �׸� -> ???, ������ ī�����常 ���
	void Draw(bool bFlip) {	// bFlip�� ���� ������ ������ �����ٰ��ΰ��� ����
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");	
	}
};

// ������ �ϴ� �÷��̾�
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	// �÷��̾��� �и� �׸�
	void Draw(bool MyTurn) {
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {	// �� ���϶��� ��ȣ ���, �ƴϸ� ����
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// ������ ����Ǵ� ���
class CBlanket : public CPlayer	// ���� ���� ������ ī�带 ������ ���� ���·� ī�带 ǥ���Ѵٴ� ���� �÷��̾�� ����
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	// ī�带 �����ٻ� �� �ʿ䰡 ���� myturn�� �μ��� �׻� false
	void Draw() {
		CPlayer::Draw(false);
	}
	// ��ġ�ϴ� ī�尡 �� �̻��̸� ���ʿ� �Ϸù�ȣ ���
	void DrawSelNum(int* pSame) {	// pSame : �Ϸù�ȣ�� ǥ���� ī���� ÷��
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	// ���� ī�� �Ʒ��� �� ī�带 ����� ��ī�尡 ��ġ���� ������
	void DrawTempCard(int idx, SCard C) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// �÷��̾ ���� ī���� ���� : ���� �п� ���� ����
class CPlayerPae : public CCardSet
{
private:
	int nGo;	// �� Ƚ��

public:
	int OldScore;	// ����
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }	// �°����� 7���̻� ���鰡��, ������������ 6������
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }	// ���ʱ�ȭ
	int GetGo() { return nGo; }		// private�̶� read�Լ� ����
	void IncreaseGo() { nGo++; }	// ��� ������ ����
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

// ���� �и� ȭ�鿡 ���� ���� �������� ���
void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {	// ��,��,���� ���ٷ� ���
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {
			gotoxy(x[3], py);	// ���� ó���� ���� ���� ���� py�� ����
			x[3] += CardGap;	
			if (x[3] > 75) {	
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "����:" << CalcScore() << "��, " << nGo << "��";
}

// ������ ������ �Ѳ����� �԰ų� �Ͼ��� ������
// �� ������ �����Ͽ� ���濡�� ��
SCard CPlayerPae::RemovePee() {
	int idx;

	idx = FindFirstCard("��");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard();	// ������ ���� �п� ����
}

// ���� ��Ģ��� ���� ���
// �� ������ ���� �����̻��� ���� 3,4,15��
// ���� ���Ե� 3���� 2��
// �ʰ� ���� �ټ������ 1��
// û��,�ʴ�, ȫ���� �� 3��
// ���� 5��
int CPlayerPae::CalcScore() {
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };	// �� ������ ���� ���� �̻��� 3,4,15������ ���

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--;	// ���� ���Ե� 3���� 2��
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5;
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;	// �ʰ� ���� �ټ������ 1��
	return NewScore;
}

// �Լ� ����
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// ���� ����
CDeck Deck(18, 9);		// ��ũ ��ġ
CPlayer South(5, 20), North(5, 1);	// �Ʒ� ����, �� �ϱ�
CBlanket Blanket(5, 12);	// ���
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);	// ���� �д� �����ʿ� ��ġ
bool SouthTurn;	// �� ���� ����

// ���α׷��� �������ϴ� main �Լ�
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

	randomize();	// ���� �߻��� �ʱ�ȭ
	Initialize();	// ��ũ�� ī�带 ���� �и� ���� ������ ������ ����
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {	// ���� ���ʺ��� ����; ��ũ�� �������� ����;ī�� �ϳ� �������� �ѹ� �ݺ�
		DrawScreen();	// �� ��ü�� ȭ�鿡 �׸���.
		// ���ʿ� ���� ��� �и� �̸� ������ ���´� -> ���ʿ� ������� �ڵ带 �Ϲ�ȭ�ϴ� ���
		if (SouthTurn) {
			Turn = &South;			// ���� ������ �÷��̾�
			TurnPae = &SouthPae;	// ���� ī�尡 �̵��� ��
			OtherPae = &NorthPae;
		}
		else {
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		// �÷��̾ ���� ī�� ������ŭ ���� �Է�
		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum());	
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) {
			if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)	// 0�� �Է��ϸ� ����
				return;
			else
				continue;
		}

		// �÷��̾ ī�带 ���� ����.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);	// �÷��̾ �� ī��
		SameNum = Blanket.FindSameCard(UserCard, arSame);	// �÷��̾ �� ī��� ��信 �� ī���� ��ġ����
		switch (SameNum) {	// ��ġ�ϴ� �������� �б�
		case 0:	// ��ġ�ϴ� ī�尡 ���� ���
			UserSel = -1;	// �ƹ��͵� ������
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));	// ��ũ���� ������ ī��� ��ġ�Ҽ� �����Ƿ� ���� ī��� ��� ��信 ����
			DrawScreen();
			break;
		case 1:	// �ϳ��� ��ġ�ϴ� ���
			UserSel = arSame[0];	// ����ڰ� ������ ī�� : UserSel
			break;
		case 2:	// �ΰ��� ��ġ�ϴ� ���
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {	// ��ī�尡 �������� �������� �ʴ´�
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame);	// ��ġ�ϴ� ī�� ����� arSame�� ��� ����� DrawSelNum�� ȣ���Ͽ� ��ȣ�� ����ϰ� 
				sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);	
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];	// ������� Ű �Է��� �޾� ���õ� ī�带 UserSel�� ����
			}
			break;
		case 3:	// ������ ��ġ�ϴ� ���
			UserSel = arSame[1];	// ��� ī�忡 ����ΰ� �����ö��� �翷�� ī�� ������� �Ѳ����� ������
			UserTriple = true;		// ������ �Ծ����� ǥ��
			break;
		}

		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard); // �÷��̾ ��ī�带 ī��Ʒ��ʿ� ǥ���ϰ� ���������� ǥ��
		}

		delay(Speed);	// ��Ȳ�� �����ֱ����� 1�ʰ� ������

		// ��ũ���� ������ �����´�.
		Deck.Draw(true);
		delay(Speed);	// ������ ī�带 �����ֱ����� ������
		DeckCard = Deck.Pop();	// ��ũ ���� ���� �ִ� ī�带 ���� ����
		SameNum = Blanket.FindSameCard(DeckCard, arSame);	// ��ũ���� ������ ī��� ����� ī�尡 ��ġ�ϴ� ������ ���� ������ ����
		
		switch (SameNum) {
		case 0:	// ��ġ�ϴ� ī�尡 ���� ���
			DeckSel = -1;	// ������ ������ ǥ��
			break;
		case 1:	// �ϳ��� ��ġ�ϴ� ���
			DeckSel = arSame[0];	// DeckSel�� ��ġ�� ī�� ÷�ڸ� ����
			if (DeckSel == UserSel) {	// ����ڰ� �� ī��� ��ũ�� ī�尡 ��ġ�ϸ� -> ����
				if (Deck.IsNotLast()) {	// ���������� �ƴ� ���
					Blanket.InsertCard(DeckCard);	// ��� ī�带 ���� �ݳ�, ��ũ ī��
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));	// ��� ī�带 ���� �ݳ�, ����ڰ� �� ī��
					OutPrompt("�����߽��ϴ�.", PromptSpeed);
					continue;	// �ƹ��͵� ���� ����
				}
				else {	
					DeckSel = -1;	// �������ǿ��� ���簡 ������ ����ڰ� �� ī�带 ������ ���������� �Ѵ�.
				}
			}
			break;
		case 2:	// �ΰ��� ��ġ�ϴ� ���
			if (UserSel == arSame[0]) {	// �÷��̾ ���س��� ī�带 ���Ѵ�. -> ����
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
					sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:	// ������ ��ġ�ϴ� ���
			DeckSel = arSame[1];
			DeckTriple = true;	// ��� ī�带 �� �����´�
			break;
		}

		if (DeckSel != -1) {	// ������ ī�带 DeckSel �ڸ��� ǥ��
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		// ��ġ�ϴ� ī�带 �ŵ� ���δ�. �� ���� ���� ���� ���� ���� �´�.
		if (UserSel != -1) {	// ����� ī�带 ���� �з� �̵�
			if (UserTriple) {	// ��信�� 3���� �����´�
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
		else {	// DeckSel�� -1�϶� ���� �̵��Ѵ�.
			Blanket.InsertCard(DeckCard);
		}

		// ��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ���´�.
		nSnatch = 0;	// ����� ī�� ����
		if (Deck.IsNotLast()) {
			// �� : ������ ī�带 ��ũ���� ������ �ٽ� �Դ� ���
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {	
				nSnatch++;
				OutPrompt("���Դϴ�.", PromptSpeed);
			}
			// ���� : �÷��̾ �� ī��� ����� ī�带 �԰� ��ũ���� ������ ī��ε� �Ե� ������ ���ڰ� ��� ��ġ�Ҷ�
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("�����Դϴ�.", PromptSpeed);
			}
			// �Ͼ��� : ��信 ���� ī�尡 �ϳ��� ���� ��
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);
			}
			// �ѹ��� ������ �Դ� ���
			if (UserTriple || DeckTriple) {
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		// nSnatch�� �ִ밪�� 3
		for (i = 0; i < nSnatch; i++) {
			TurnPae->InsertCard(OtherPae->RemovePee());
		}

		// ������ ����ϰ� ��, ���� ���θ� �����Ѵ�.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {	// �������� OldScore���� Ŀ���ٸ� go/stop
			DrawScreen();
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:���)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;	// ���� ����
				TurnPae->IncreaseGo();			// �� Ƚ�� ����
			}
			else {	// ���ǿ��� ������ ����
				break;
			}
		}
	}
	DrawScreen();
	OutPrompt("������ �������ϴ�.", 0);
}

/* ����� �Լ� */
// ��ũ�� �и� �������� ���� ī�带 �ʱ�ȭ
void Initialize()
{
	int i;

	Deck.Shuffle();
	for (i = 0; i < 10; i++) { // �÷��̾����� 10�徿
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8) Blanket.InsertCard(Deck.Pop());	// ��ũ�� 8��
	}
}

//ȭ���� ����� ��� ��ü�� Draw�Լ��� ���ʴ�� ȣ��
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

// �ϴܿ� ª�� �޽����� ���
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);	// ����ڰ� �޽����� �������� ��� ��ٸ���.
}

// ������ ������ ���� �ϳ��� �Է¹���
// ���� ī����� ���� ������ ������ ������
int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(_getch());
		if (ch == 0xE0 || ch == 0) {	
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';	// A��� 10
		if (ch >= start && ch <= end) {	
			return ch;
		}
		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");
	}
}

