/*1.Класс Интервал
Создать класс Interval, представляющий собой отрезок, задаваемый двумя
числами на прямой – начало и конец интервала (типа float).
1) Написать конструкторы класса
a) Конструктор по умолчанию, задающий начало и конец интервала равными
нулю
b) Конструктор с параметрами, устанавливающий значения начала и конца
интервала (в случае если передаваемый конец интервала меньше начала,
поменять их местами)
c) Конструктор копирования
2) Перегрузить оператор присваивания
3) Реализовать методы класса
a) Для нахождения длины интервала
b) Установка и получения значений начала и конца интервала
c) Move(float dist); – функция сдвигает начало и конец интервала на
расстояние dist с сохранением его длины
d) Expand(float scale) - увеличивает длину интервала в scale раз с
сохранением его начала
e) float Mid() - возвращает точку середину интервала
f) bool IsEmpty() – возвращает true в случае, если длина интервала равна 0
(начало совпадает с концом)
4) Перегрузить операторы
a) & – пересечение двух интервалов. Возвращает интервал, содержащийся в
пересечении интервалов, либо пустой интервал, если они не
пересекаются.
b) | – объединение интервалов. Возвращает интервал, включающий первый
и второй интервал, если между ними нет промежутка. В противном случае
– пустой интервал.
c) void operator+=(float dist) –  то, что делает функция Move.
d) void operator*=(float scale) –  то, что делает функция Expand.
e) Операторы записи в поток и чтения из потока. В поток выводить в виде
строки "1.2 5.6" , где через пробел идут начало и конец интервала.*/

#include "Interval.h"
#include <cstdio>

int main()
{
	Interval interval1;
	Interval interval2(1.1, 3.3);

	interval1 = interval2;

	std::printf("The length of intervals 1 and 2: %f\n", interval1.CalculateLength());

	interval2.GetInterval();
	interval1.MoveDist(2.3);
	
	std::printf("Interval #1 coordinate: ");
	std::cout << interval1;

	interval1.Expand(5);

	std::printf("Interval #1 coordinate: ");
	std::cout << interval1;

	std::printf("Interval #2 coordinate: ");
	std::cout << interval2;

	std::printf("The middle of interval 2: %f\n", interval2.CalculateMiddle());

	std::printf("The interval 2 is empty or not:");

	if (interval2.IsEmpty())
	{
		std::printf("Yes\n");
	}
	else
	{
		std::printf("Not\n");
	}

	std::printf("The intersection of the intervals 1 and 2: ");
	Interval interval3 = interval1 & interval2;
	std::cout << interval3;

	std::printf("The union of the intervals 1 and 2: ");
	interval3 = interval1 | interval2;
	std::cout << interval3;

	return 0;
}