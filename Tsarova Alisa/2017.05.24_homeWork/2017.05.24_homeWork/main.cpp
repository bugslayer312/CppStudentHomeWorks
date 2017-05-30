/*Задание 1. Работа с классами
Реализовать класс трехмерного вектора, у которого имеются вещественные
координаты x, y, z.
Написать для класса конструкторы :
а) по умолчанию(инициализирует все три координаты нулями)
б) с параметрами(инициализирует все три координаты передаваемыми
значениями)
Написать методы для доступа к полям класса.
Написать метод для установки полей класса.
Написать методы для получения координат с консоли и печати их на консоль :
Read(), Print().
Написать метод, прибавляющий к вектору другой вектор.
Написать метод для нахождения длины вектора : | v | = sqrt(x2 + y2 + z2).
Написать метод для нахождения скалярного произведения двух векторов https ://
ru.wikipedia.org / wiki / Скалярное_произведение
v1*v2 = x1*x2 + y1*y2 + z1*z2.Результатом будет число.
Написать метод для нахождения косинуса угла между векторами через скалярное
произведение : v1*v2 = | v1 | *| v2 | *cos(a).
Написать метод для нахождения векторного произведения векторов https ://
ru.wikipedia.org / wiki / Векторное_произведение
v3 = v1 x v2.Результатом будет вектор со следующими координатами :
x3 = y1*z2 - z1*y2;
y3 = z1*x2 - x1*z2;
z3 = x1*y2 - y1*x2*/

#include <iostream>
#include "vector.h"

int main()
{
	std::cout << "This program for creating vectors, that using simple math." << std::endl;

	Vector vector1;	
	float xPos, yPos, zPos;
	
	std::cout << "Lets create a Vector #1:" << std::endl;
	vector1.WriteValue();
	
	std::cout << "Lets create a Vector #2:" << std::endl;
	std::cout << "Please, enter x coordinate of vector: ";
	std::cin >> xPos;
	std::cout << "Please, enter y coordinate of vector: ";
	std::cin >> yPos;
	std::cout << "Please, enter z coordinate of vector: ";
	std::cin >> zPos;
	
	Vector vector2(xPos, yPos, zPos);
	
	std::cout << "Vector #1 coordinate: " << std::endl;
	vector1.PrintCoordinate();

	std::cout << "Vector #2 coordinate: " << std::endl;
	vector2.PrintCoordinate();

	Vector vectorSummResult;

	vectorSummResult = vector1 + vector2;

	std::cout << "Vector #2 + Vector #3: " << std::endl;
	vectorSummResult.PrintCoordinate();

	float vectorScalarResult;

	vectorScalarResult = vector1 * vector2;

	std::cout << "The scalar product of vectors #1 and #2:" << std::endl;
	std::cout << vectorScalarResult << std::endl;

	std::cout << "The length of vector #1: " << vector1.FindLengthVector() << std::endl;
	std::cout << "The length of vector #2: " << vector2.FindLengthVector() << std::endl;

	std::cout << "The cosine of the angle vectors #1 and #2: " << vector1.FindCosVectors(vector2) << std::endl;

	Vector multipleVectors;

	multipleVectors = vector1.FindMultipleVectors(vector2);

	std::cout << "The vector products of vectors #1 and #2: " << std::endl;
	multipleVectors.PrintCoordinate();

	return 0;
}