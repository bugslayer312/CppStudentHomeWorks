#include "Vector.h"
#include <iostream>


int main()
{
	Vector <float, 3> vector1;
	Vector <float, 4> vector2(vector1);
	Vector <float, 3> vector3 = {1.3F, 1.5F, 6.2F};

	int a = 3;
	//vector1 = vector3 * a;
	
	std::cout << vector3[1] << std::endl;
	
	return 0;
}