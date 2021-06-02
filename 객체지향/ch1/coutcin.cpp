#include<iostream>	// C++의 기본 헤더파일

// using namespace std;	// C++ 표준 라이브러리에 정의되어있음

int main()
{
	std::cout << "***cout 예제***" << std::endl;

	std::cout << "First C++ Program" << std::endl;

	int i = 56;
	char ch = 'S';
	double d = 2.414;

	std::cout << i << ch << d << std::endl << std::endl;



	std::cout << "***cin 예제***" << std::endl;

	int age;
	std::cout << "나이를 입력하시오: ";
	std::cin >> age;
	std::cout << "당신은 " << age << "살입니다." << std::endl;
}