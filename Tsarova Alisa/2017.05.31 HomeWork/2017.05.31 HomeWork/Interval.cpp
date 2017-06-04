#include "Interval.h"
#include <iostream>

Interval::Interval() : m_start(0), m_end(0)
{
}

Interval::Interval(float start, float end) : m_start(start), m_end(end)
{
	if (m_end < m_start)
	{
		float buff = m_start;
		m_start = m_end;
		m_end = buff;
	}
}

Interval::Interval(Interval const& interval)
{
	m_start = interval.m_start;
	m_end = interval.m_end;
}

Interval& Interval::operator=(Interval const& interval)
{
	if (this != &interval)
	{
		m_start = interval.m_start;
		m_end = interval.m_end;
	}
	return (*this);
}

float Interval::CalculateLength() const
{
	return (m_end - m_start);
}

void Interval::GetInterval()
{
	do
	{
		std::cout << "\nPlease enter the start of interval: " << std::endl;
		std::cin >> m_start;
		std::cout << "\nPlease enter the end of interval: " << std::endl;
		std::cin >> m_end;
	} while (m_start > m_end);
}

void Interval::MoveDist(float move)
{
	m_start += move;
	m_end += move;
}

void Interval::Expand(float scale)
{
	m_end *= scale * CalculateLength() + m_start;
}

float Interval::CalculateMiddle() const
{
	return (CalculateLength() / 2) + m_start;
}

bool Interval::IsEmpty() const
{
	if (m_start == m_end)
	{
		return true;
	}
	return false;
}

Interval Interval::operator&(Interval const& interval)
{
	Interval result;
	if (m_start <= interval.m_start)
	{
		result.m_start = interval.m_start;
	}
	else
	{
		result.m_start = m_start;
	}
	if (m_end >= interval.m_end)
	{
		result.m_end = interval.m_end;
	}
	else
	{
		result.m_end = m_end;
	}

	if (result.m_start > result.m_end)
	{
		result.m_start = 0;
		result.m_end = 0;
	}
	
	return result;
}

Interval Interval::operator|(Interval const& interval)
{
	Interval result;

	if (m_start <= interval.m_start)
	{
		result.m_start = m_start;
	}
	else
	{
		result.m_start = interval.m_start;
	}
	if (m_end >= interval.m_end)
	{
		result.m_end = m_end;
	}
	else
	{
		result.m_end = interval.m_end;
	}

	if ((this->CalculateLength() + interval.CalculateLength()) < result.CalculateLength())
	{
		result.m_start = 0;
		result.m_end = 0;
	}
	return result;
}

void Interval::operator += (float move)
{
	MoveDist(move);
}

void Interval::operator *= (float scale)
{
	Expand(scale);
}

std::ostream& operator<<(std::ostream& stream, Interval const& interval)		//ссылка для того, чтобы не копировать а изменить
{
	stream << interval.m_start << " " << interval.m_end << std::endl;
	return stream;
}

std::istream& operator >> (std::istream& stream, Interval const& interval)
{
	char buffer[30];
	stream.getline(buffer, 30 - 1);
	sscanf(buffer, "%f %f", &interval.m_start, &interval.m_end);
	return stream;
}