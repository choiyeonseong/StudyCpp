#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name, addr;

	cout << "�̸��� �Է��Ͻÿ� : ";
	cin >> name;
	cout << "�Է��� �̸��� " << name << "�Դϴ�." << endl;
	cin.ignore();	// cin�� �Է� �� ���� �ڵ带 ���ۿ� ���ܼ� ���ο� ���ڿ��� �������� ���۸� �������
	cout << "�ּҸ� �Է��Ͻÿ� : ";
	getline(cin, addr);	// ���ڿ� �Է�
	cout << "�Է��� �ּҴ� " << addr << "�Դϴ�." << endl;
}