#include<iostream>	// C++�� �⺻ �������

// using namespace std;	// C++ ǥ�� ���̺귯���� ���ǵǾ�����

int main()
{
	std::cout << "***cout ����***" << std::endl;

	std::cout << "First C++ Program" << std::endl;

	int i = 56;
	char ch = 'S';
	double d = 2.414;

	std::cout << i << ch << d << std::endl << std::endl;



	std::cout << "***cin ����***" << std::endl;

	int age;
	std::cout << "���̸� �Է��Ͻÿ�: ";
	std::cin >> age;
	std::cout << "����� " << age << "���Դϴ�." << std::endl;
}