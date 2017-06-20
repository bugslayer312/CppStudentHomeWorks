#include "Vector.h"
#include <iostream>


int main()
{
	Vector <int, 3> vector1;
	Vector <int, 4> vector2(vector1);
	Vector <int, 3> vector3 = {1, 2, 6};

	vector1 = vector3 * 56;
	
	std::cout << vector1[1] << std::endl;
	
	return 0;
}