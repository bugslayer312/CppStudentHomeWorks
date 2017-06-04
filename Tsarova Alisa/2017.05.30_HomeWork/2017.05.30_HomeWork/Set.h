#pragma once
#include <iosfwd>

class Set
{
private:
	int* m_elements;
	int m_capacity;
	int m_count;

public:
	Set();
	Set(int element);
	Set(Set const& set);
	~Set();

	void ExpendMemory();
	void operator+=(int element);
	void operator-=(int element);
	bool Contains(int element) const;

	Set& operator=(Set const& set);
	size_t GetCount();

	bool operator==(Set const& rhs) const;
	void PrintElements();
	bool operator!= (Set const& rhs) const;
	friend Set operator& (Set const& left, Set const& right);
	friend Set operator| (Set const& left, Set const& right);
	friend Set operator^ (Set const& left, Set const& right);
	friend std::ostream& operator<<(std::ostream& stream, Set const& set);
	friend std::istream& operator >> (std::istream& stream, Set& set);
	operator bool() const;
};

Set operator&(Set const& left, Set const& right);
Set operator|(Set const& left, Set const& right);
Set operator^(Set const& left, Set const& right);
std::ostream& operator<<(std::ostream& stream, Set const& set);
std::istream& operator >> (std::istream& stream, Set& set);