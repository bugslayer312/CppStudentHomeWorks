#include "Stack.h"

Stack::Stack() : m_count(0), m_capacity(10)
{
	m_array = new int[m_capacity];
}

Stack::Stack(Stack const& stack)
{
	m_count = stack.m_count;
	m_capacity = stack.m_capacity;
	m_array = new int[m_capacity];
	memcpy(m_array, stack.m_array, m_count);
}

Stack::~Stack()
{
	delete[] m_array;
}

void Stack::ReallocateMemory(int capacity)
{
	m_capacity = capacity;
	int* newMemory;
	newMemory = new int[m_capacity];
	memcpy(newMemory, m_array, sizeof(int) * m_count);
	delete[] m_array;
	m_array = newMemory;
}

Stack& Stack::operator=(const Stack& stack)
{
	if (this != &stack)
	{
		m_capacity = stack.m_capacity;
		m_count = stack.m_count;
		m_array = new int[m_capacity];
		memcpy(m_array, stack.m_array, sizeof(int) * m_count);
	}
	return *this;
}

void Stack::Push(int element)
{
	if (m_count >= m_capacity)
	{
		ReallocateMemory(m_capacity * 2);
	}
	m_array[m_count] = element;
	m_count++;
}

int Stack::Pop()
{
	if (m_capacity >= m_count * 4)
	{
		ReallocateMemory(m_capacity / 2);
	}
	return m_array[--m_count];
}

size_t Stack::GetCount() const
{
	return m_count;
}

int Stack::Top() const
{
	return m_array[m_count - 1];
}

void Stack::Clear()
{
	m_count = 0;
	m_capacity = 10;
	ReallocateMemory(m_capacity);
}

Stack& Stack::operator << (int element)
{
	Push(element);
	return *this;
}

Stack& Stack::operator >> (int& element)
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_array[i] == element)
		{
			Pop();
		}
	}
	return *this;
}