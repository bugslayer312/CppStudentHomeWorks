#pragma once

class Vector
{
private:
	float m_xСoordinate;
	float m_yСoordinate;
	float m_zСoordinate;

public:
	Vector();
	Vector(float xCoordinate, float yCoordinate, float zCoordinate);

	float GetX() const;
	float GetY() const;
	float GetZ() const;
	void SetValue(float xСoordinate, float yСoordinate, float zСoordinate);
	void WriteValue();
	void PrintCoordinate() const;
	Vector operator+(Vector const& vector);
	float operator*(Vector const& vector);
	float CalculateLength() const;
	float CalculateCos(Vector const& vector);
	Vector CalculateVectorProduct(Vector const& vector);
};