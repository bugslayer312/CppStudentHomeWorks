#pragma once

#include <iostream>
#include <initializer_list>
#include <iosfwd>

template<class T>
class DynArray;

template<class T>
class DynArrayIterator
{
private:
	T* index;

public:
	DynArrayIterator() : index(nullptr)
	{
	}

	DynArrayIterator(T* in) : index(in)
	{
	}
	
	T& operator*()
	{
		return *index;
	}

	DynArrayIterator<T> operator++()
	{
		T* ptr = this->index;
		ptr += 1;
		this->index = ptr;
		return *this;
	}

	DynArrayIterator<T> operator--()
	{
		T* ptr = this->index;
		ptr -= 1;
		this->index = ptr;
		return *this;
	}

	DynArrayIterator<T> operator+(int step)
	{
		T* ptr = this->index;
		ptr += step;
		this->index = ptr;
		return *this;
	}

	DynArrayIterator<T> operator-(int step)
	{
		T* ptr = this->index;
		ptr -= step;
		this->index = ptr;
		return *this;
	}

	bool operator==(DynArrayIterator<T> const& iterator)
	{
		return this->index == iterator.index;
	}

	bool operator!=(DynArrayIterator<T> const& iterator)
	{
		return !(*this == iterator);
	}
};

template<class T>
class DynArray
{
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;

public:
	typedef DynArrayIterator<T> iterator;
	DynArray() = default;
	DynArray(size_t capacity);
	DynArray(DynArray const& rhs);
	DynArray(DynArray&& rhs);
	DynArray(std::initializer_list<T> const& list);
	DynArray& operator=(DynArray const& rhs);
	DynArray& operator=(DynArray&& rhs);

	void reserve(size_t newCapacity);
	size_t Size() const;
	size_t Capacity() const;

	void PushBack(T const& item);
	void PopBack();
	void Clear();

	T& operator[](size_t idx);
	T const& operator[](size_t idx) const;
	
	iterator begin();
	iterator end();

	int ReturnIndex(iterator const& it);

	void Insert(iterator const& it, T const& element);

	void Erase(iterator const& it);

	void PrintArray();
};

template<class T>
void DynArray<T>::PrintArray()
{
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_data[i] << " ";
	}
}

template<class T>
DynArray<T>::DynArray(size_t capacity) :
	m_capacity(capacity)
{
	if (m_capacity > 0)
	{
		m_data = new T[m_capacity];
	}
}

template<class T>
DynArray<T>::DynArray(DynArray const& rhs) :
	m_capacity(rhs.m_capacity),
	m_size(rhs.m_size)
{
	if (m_capacity > 0)
	{
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
		{
			m_data[i] = rhs.m_data[i];
		}
	}
}

template<class T>
DynArray<T>::DynArray(DynArray&& rhs) :
	m_capacity(rhs.m_capacity),
	m_size(rhs.m_size),
	m_data(rhs.m_data)
{
	rhs.m_capacity = 0;
	rhs.m_size = 0;
	rhs.m_data = nullptr;
}

template<class T>
DynArray<T>::DynArray(std::initializer_list<T> const& list)
{
	size_t size = list.size();
	if (size > 0)
	{
		m_size = m_capacity = size;
		m_data = new T[m_capacity];
		T* ptr = m_data;
		typedef typename std::initializer_list<T>::iterator iterator;
		for (iterator it = list.begin(); it != list.end(); ++it)
		{
			*(ptr++) = *it;
		}
	}
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T> const& rhs)
{
	if (&rhs != this)
	{
		DynArray<T> temp(rhs);      // copy to temp
		*this = std::move(temp);    // grabbing data from temp
	}
	return *this;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T>&& rhs)
{
	if (&rhs != this)
	{
		delete[] m_data;
		m_capacity = rhs.m_capacity;
		m_size = rhs.m_size;
		m_data = rhs.m_data;

		rhs.m_capacity = 0;
		rhs.m_size = 0;
		rhs.m_data = nullptr;
	}
	return *this;
}

template<class T>
void DynArray<T>::reserve(size_t newCapacity)
{
	if (m_capacity == newCapacity)
	{
		return;
	}
	
	m_capacity = newCapacity;

	if (m_size > m_capacity)
	{
		m_size = m_capacity;
	}
	DynArray<T> buff(*this);
	*this = std::move(buff);
}

template<class T>
size_t DynArray<T>::Size() const
{
	return m_size;
}

template<class T>
size_t DynArray<T>::Capacity() const
{
	return m_capacity;
}

template<class T>
void DynArray<T>::PushBack(T const& item)
{
	if (m_size == m_capacity)
	{
		reserve(m_capacity > 0 ? m_capacity * 2 : 5);
	}
	m_data[m_size++] = item;
}

template<class T>
void DynArray<T>::PopBack()
{
	if (m_size)
	{
		--m_size;
		if (m_size < m_capacity / 4)
		{
			reserve(m_capacity / 2);
		}
	}
}

template<class T>
void DynArray<T>::Clear()
{
	if (m_capacity > 0)
	{
		m_capacity = 0;
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
	}
}

template<class T>
T& DynArray<T>::operator[](size_t idx)
{
	if (idx >= m_size || idx < 0)
	{
		std::cout << "Invalid index\n" << idx << std::endl;
		exit(1);
	}
	return m_data[idx];
}

template<class T>
T const& DynArray<T>::operator[](size_t idx) const
{
	DynArray<T>* nonConstThis = const_cast<DynArray<T>*>(this);
	return (*nonConstThis)[idx];
}

template<class T>
DynArrayIterator<T> DynArray<T>::begin()
{
	return DynArrayIterator<T>(m_data);
}

template<class T>
DynArrayIterator<T> DynArray<T>::end()
{
	return DynArrayIterator<T>(m_data + m_size);
}

template<class T>
int DynArray<T>::ReturnIndex(iterator const& it)
{
	DynArrayIterator<T> iter = this->begin();
	size_t i = 0;
	for (; i < m_size; i++)
	{
		if (iter == it)
		{
			return i;
		}
		++iter;
	}
	return -1;
}

template<class T>
void DynArray<T>::Insert(iterator const& it, T const& element)
{
	if (m_size == 0)
	{
		m_size += 1;
		m_capacity = 5;
		reserve(m_capacity);
		m_data[0] = element;
	}

	int index = this->ReturnIndex(it);

	if (index < m_size && index >= 0)
	{
		m_size += 1;
		m_capacity += 1;
		reserve(m_capacity);

		for (int i = m_size - 1; i >= index; i--)
		{
			m_data[i + 1] = m_data[i];
		}
		m_data[index] = element;
	}
	else
	{
		std::cout << "Error\n";
		exit(1);
	}
}

template<class T>
void DynArray<T>::Erase(iterator const& it)
{
	if (m_size == 0)
	{
		std::cout << "Error\n";
		exit(1);
	}

	size_t index = this->ReturnIndex(it);
	
	if (index < m_size && index >= 0)
	{
		for (size_t i = index; i < m_size - 1; i++)
		{
			m_data[i] = m_data[i + 1];
		}
		m_data[m_size - 1] = 0;

		m_size -= 1;
		m_capacity = m_size < m_capacity / 4 ? m_capacity / 2 : m_capacity + 1;
		reserve(m_capacity);
	}
}