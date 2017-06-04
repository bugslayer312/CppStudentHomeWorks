#include "Set.h"
#include <iostream>
#include <iosfwd>

Set::Set():m_capacity(5), m_count(0)
{
	m_elements = new int[m_capacity];
}

Set::Set(int element)
{
	m_capacity = 5;
	m_count = 0;
	m_elements = new int[m_capacity];
	m_elements[m_count] = element;
	m_count++;
}

Set::Set(Set const& set) : m_capacity(set.m_capacity), m_count(set.m_count)
{
	m_elements = new int[m_capacity];
	memcpy(m_elements, set.m_elements, m_count * sizeof(int));
}

Set::~Set()
{
	delete[] m_elements;
}

void Set::ExpendMemory()
{
	m_capacity *= 2;
	int* newMemory = new int[m_capacity];
	memcpy(newMemory, m_elements, m_count * sizeof(int));
	delete[] m_elements;
	m_elements = newMemory;
}

void Set:: operator+=(int element)
{
	if (!Contains(element))
	{
		if (m_count == m_capacity)
		{
			ExpendMemory();
		}
		m_elements[m_count++] = element;
	}
}

void Set:: operator-=(int element)
{
	if (Contains(element))
	{
		for (int i = 0; i < m_count; i++)
		{
			if (m_elements[i] == element)
			{
				for (int j = 0; j < m_count - 1; j++)
				{
					m_elements[j] = m_elements[j + 1];
				}
			}
		}
		m_count--;
	}
}

bool Set::Contains(int element) const
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_elements[i] == element)
		{
			return true;
		}
	}
	return false;
}

Set& Set::operator=(Set const& set)
{
	if (this != &set)
	{
		m_capacity = set.m_capacity;
		m_count = set.m_count;
		m_elements = new int[m_capacity];
		memcpy(m_elements, set.m_elements, sizeof(int) * m_count);
	}
	return *this;
}

size_t Set::GetCount()
{
	return m_count;
}

bool Set::operator==(Set const& set) const
{
	if (m_count == set.m_count)
	{
		for (int i = 0; i < m_count; i++)
		{
			if (!set.Contains(m_elements[i]))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void Set::PrintElements()
{
	for (int i = 0; i < m_count; i++)
	{
		std::cout << "Element" << "[" << i << "]" << m_elements[i] << std::endl;
	}
}

bool Set::operator!= (Set const& rhs) const
{
	return !(*this == rhs);
}

Set operator&(Set const& left, Set const& right)
{
	Set result;
	for (int i = 0; i < left.m_count; i++)
	{
		if (right.Contains(left.m_elements[i]))
		{
			result += left.m_elements[i];
		}
	}
	return result;
}

Set operator|(Set const& left, Set const& right)
{
	Set result(left);

	for (int i = 0; i < right.m_count; i++)
	{
		result += right.m_elements[i];
	}

	return result;
}

Set operator^(Set const& left, Set const& right)
{
	Set result = left | right;
	for (int i = 0; i < left.m_count; i++)
	{
		for (int j = 0; j < right.m_count; j++)
		{
			if (left.m_elements[i] == right.m_elements[j])
			{
				result -= right.m_elements[j];
			}
		}
	}
	return result;
}

Set::operator bool() const
{
	return m_count > 0;
}

std::ostream& operator<<(std::ostream& stream, Set const& set)		
{
	for (int i = 0; i < set.m_count; i++)
	{
		stream << set.m_elements[i] << " ";
	}
	
	return stream;
}

std::istream& operator >> (std::istream& stream, Set& set)
{
	char buffer[20];
	stream.getline(buffer, 19);										
	char* begin = buffer;
	set += strtol(begin++, &begin, 10);									
	do 
	{
		set += strtol(++begin, &begin, 10);									
	} while (*begin == ' ');

	return stream;
}