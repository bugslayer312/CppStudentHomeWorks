#pragma once

class Interval
{
private:
	float m_start;
	float m_end;

public:
	Interval();
	Interval(float start, float end);
	Interval(Interval const& interval);
	void operator=(Interval const& interval);
	float CalculateLength();
	void GetInterval();
	void MoveDist(float move);
	void Expand(float scale);
	float CalculateMiddle();
	bool IsEmpty();
	Interval operator&(Interval interval);
	Interval operator|(Interval interval);
	void operator += (float move);
	void operator *= (float scale);
	friend std::ostream& operator<<(std::ostream& stream, Interval const& interval);
	friend std::istream& operator >> (std::istream& stream, Interval const& interval);
};

std::ostream& operator<<(std::ostream& stream, Interval const& interval);
std::istream& operator>>(std::istream& stream, Interval const& interval);