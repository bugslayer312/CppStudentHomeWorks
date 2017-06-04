#include "Complex.h"
#include <iostream>

Complex::Complex():m_Re(0), m_Im(0)
{
}

Complex::Complex(float re, float im):m_Re(re), m_Im(im)
{
}

Complex::Complex(float re) :m_Re(re), m_Im(0)
{
}

Complex::Complex(Complex const& complex)
{
	m_Re = complex.m_Re;
	m_Im = complex.m_Im;
}

Complex& Complex::operator=(Complex const& complex)
{
	if (this != &complex)
	{
		m_Im = complex.m_Im;
		m_Re = complex.m_Re;
	}
	return *this;
}

float Complex::GetRe() const
{
	return m_Re;
}

float Complex::GetIm() const
{
	return m_Im;
}

void Complex::Set(float re, float im)
{
	m_Re = re;
	m_Im = im;
}

float Complex::CalculateModule() const
{
	return sqrt(m_Re * m_Re + m_Im * m_Im);
}

Complex Complex::operator+(Complex const& complex)
{
	Complex result;

	result.m_Re = m_Re + complex.m_Re;
	result.m_Im = m_Im + complex.m_Im;

	return result;
}

Complex Complex::operator-(Complex const& complex)
{
	Complex result;

	result.m_Re = m_Re - complex.m_Re;
	result.m_Im = m_Im - complex.m_Im;

	return result;
}

Complex Complex::operator*(Complex const& complex)
{
	Complex result;

	result.m_Re = m_Re * complex.m_Re - m_Im * complex.m_Im;
	result.m_Im = m_Im * complex.m_Re + m_Re * complex.m_Im;

	return result;
}

Complex Complex::operator/(Complex const& complex)
{
	Complex result;

	result.m_Re = (m_Re * complex.m_Re + m_Im * complex.m_Im) / (m_Im * m_Im + complex.m_Im * complex.m_Im);
	result.m_Im = (m_Im * complex.m_Re + m_Re * complex.m_Im) / (m_Im * m_Im + complex.m_Im * complex.m_Im);;

	return result;
}

std::ostream& operator<<(std::ostream& stream, Complex const& complex)
{
	stream << complex.m_Re;
	if (complex.m_Im >= 0)
	{
		std::cout << "+";
	}
	std::cout << complex.m_Im << "i" << std::endl;

	return stream;
}

std::istream& operator>>(std::istream& stream, Complex& complex)
{
	char buffer[30];
	stream.getline(buffer, 30 - 1);
	char* begin = buffer;
	complex.m_Re = strtof(begin++, &begin);
	complex.m_Im = strtof(begin++, &begin);
	if (*begin != 'i')
	{
		std::cout << "Wrong ipunt\n";
		exit(1);
	}
	return stream;
}