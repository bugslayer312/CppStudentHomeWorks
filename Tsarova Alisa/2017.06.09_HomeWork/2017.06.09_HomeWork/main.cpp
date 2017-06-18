#include "Vector.h"
#include <iostream>


int main()
{
	Vector <float, 3> vector1;
	Vector <float, 4> vector2(vector1);
	Vector <float, 3> vector3 = {1.3F, 1.5F, 6.2F};

	float a = 3;
	vector1 = vector3 * 56;
	
	std::cout << vector1[1] << std::endl;
	
	return 0;
}