#include "Complex.h"
#include <iostream>

int main()
{
	Complex c1(3, 4);
	Complex c2(-65, -5);

	Complex c3;

	c3 = c1 + c2;

	std::cout << c3;

	Complex c4;

	std::cin >> c4;
	return 0;
}