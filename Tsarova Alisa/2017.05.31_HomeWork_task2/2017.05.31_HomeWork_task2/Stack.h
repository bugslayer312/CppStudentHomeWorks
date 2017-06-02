#pragma once

#include <iostream>

class Stack
{
private:
	int* m_array;
	int m_count;
	int m_capacity;

public:
	Stack();
	Stack(Stack const& stack);
	~Stack();
	void ReallocateMemory(int capacity);
	Stack& operator=(const Stack& stack);
	void Push(int element);
	int Pop();
	size_t GetCount() const;
	int Top() const;
	void Clear();
	Stack& operator << (int element);
	Stack& operator >> (int& element);
};