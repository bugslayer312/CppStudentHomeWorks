#pragma once
#include <initializer_list>
#include <iostream>

template <class T, int N>
class Vector
{
public:
	T m_coordinate[N];

	Vector();

	template <int N1>
	Vector(Vector<T, N1> const& vector);

	Vector(std::initializer_list<T> const& list);

	template<int N1>
	Vector<T, N>& operator=(Vector<T, N1> rhs);

	T& operator[](int index);

	template<class T1>
	Vector<T1, N> operator*(T1 number);
};

template <class T, int N>
Vector<T, N>::Vector() 
{
	memset(m_coordinate, 0, sizeof(m_coordinate));
}

template <class T, int N>
template <int N1>
Vector<T, N>::Vector(Vector<T, N1> const& vector)
{
	for (int i = 0; i < N; ++i)
	{
		m_coordinate[i] = i < N1 ? vector.m_coordinate[i] : T();
	}
}

template <class T, int N>
Vector<T, N>::Vector(std::initializer_list<T> const& list)
{
	std::initializer_list<T>::iterator it = list.begin();
	T* ptr = m_coordinate;
	int i = 0;
	for (; it != list.end() && i < N; ++it)
	{
		m_coordinate[i] = *it;
		i++;
	}
}

template<class T, int N>
template<int N1>
Vector<T, N>& Vector<T, N>::operator=(Vector<T, N1> rhs)
{
	if ((void*)this != (void*)&rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			m_coordinate[i] = (i < N1 ? rhs.m_coordinate[i] : T());
		}
	}
	return *this;
}

template<class T, int N>
T& Vector<T, N>::operator[](int index)
{
	if (index < 0 || index >= N)
	{
		std::cout << "The wrong pointer";
		exit(0);
	}
	return m_coordinate[index];
}

template <class T, int N>
template<class T1>
Vector<T1, N> Vector<T, N>::operator*(T1 number)
{
	Vector<T, N1> result(*this);
	for (int i = 0, i < N, i++)
	{
		result.m_coordinate[i] *= number;
	}
	return result;
}