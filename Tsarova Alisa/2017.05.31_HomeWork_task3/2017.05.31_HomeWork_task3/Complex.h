#pragma once
#include <cmath>
#include <iosfwd>

class Complex
{
private:
	float m_Re;
	float m_Im;

public:
	Complex();
	Complex(float re, float im);
	Complex(float re);
	Complex(Complex const& complex);
	Complex& operator=(Complex const& complex);
	float GetRe() const;
	float GetIm() const;
	void Set(float re, float im);
	float CalculateModule() const;
	Complex operator+(Complex const& complex);
	Complex operator-(Complex const& complex);
	Complex operator*(Complex const& complex);
	Complex operator/(Complex const& complex);
	friend std::ostream& operator<<(std::ostream& stream, Complex const& complex);
	friend std::istream& operator>>(std::istream& stream, Complex& complex);
};

std::ostream& operator<<(std::ostream& stream, Complex const& complex);
std::istream& operator>>(std::istream& stream, Complex& complex);