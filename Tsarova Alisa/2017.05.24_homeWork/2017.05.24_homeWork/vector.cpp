#include <iostream>
#include "vector.h"

Vector::Vector() :
	m_xСoordinate(0), m_yСoordinate(0), m_zСoordinate(0)
{
}

Vector::Vector(float xCoordinate, float yCoordinate, float zCoordinate) :
	m_xСoordinate(xCoordinate), m_yСoordinate(yCoordinate), m_zСoordinate(zCoordinate)
{
}

float Vector::GetX() const
{
	return m_xСoordinate;
}

float Vector::GetY() const
{
	return m_yСoordinate;
}

float Vector::GetZ() const
{
	return m_zСoordinate;
}

void Vector::SetValue(float xСoordinate, float yСoordinate, float zСoordinate)
{
	m_xСoordinate = xСoordinate;
	m_yСoordinate = yСoordinate;
	m_zСoordinate = zСoordinate;
}

void Vector::WriteValue()
{
	std::cout << "Enter the x coordinate: \n";
	std::cin >> m_xСoordinate;
	std::cout << "Enter the y coordinate: \n";
	std::cin >> m_yСoordinate;
	std::cout << "Enter the z coordinate: \n";
	std::cin >> m_zСoordinate;
}

void Vector::PrintCoordinate() const
{
	std::cout << "X coordinate: " << m_xСoordinate << std::endl;
	std::cout << "Y coordinate: " << m_yСoordinate << std::endl;
	std::cout << "Z coordinate: " << m_zСoordinate << std::endl;
}

Vector Vector::operator+(Vector vector)
{
	Vector result(*this);

	result.m_xСoordinate += vector.m_xСoordinate;
	result.m_yСoordinate += vector.m_yСoordinate;
	result.m_zСoordinate += vector.m_zСoordinate;

	return result;
}

float Vector::FindLengthVector() //| v | = sqrt(x2 + y2 + z2)
{
	float lengthVector;

	lengthVector = std::sqrt(m_xСoordinate * m_xСoordinate + m_yСoordinate * m_yСoordinate + m_zСoordinate * m_zСoordinate);

	if (lengthVector < 0)
	{
		lengthVector = std::abs(lengthVector);
	}

	return lengthVector;
}

float Vector::operator*(Vector vector) //v1*v2 = x1*x2 + y1*y2 + z1*z2
{
	float result;
	
	result = m_xСoordinate * vector.m_xСoordinate + m_yСoordinate * vector.m_yСoordinate + m_zСoordinate * vector.m_zСoordinate;
	return result;
}

float Vector::FindCosVectors(Vector vector)
{
	Vector vectorA(*this);

	float cosine;

	cosine = vectorA * vector / vectorA.FindLengthVector() * vector.FindLengthVector();

	return cosine;
}

Vector Vector::FindMultipleVectors(Vector vector)
{
	Vector result;

	result.m_xСoordinate = m_yСoordinate * vector.m_zСoordinate - m_zСoordinate * vector.m_yСoordinate;
	result.m_yСoordinate = m_zСoordinate * vector.m_xСoordinate - m_xСoordinate * vector.m_zСoordinate;
	result.m_zСoordinate = m_xСoordinate * vector.m_yСoordinate - m_yСoordinate * vector.m_xСoordinate;

	return result;
}

