/*Задание 1. Работа с классами
Реализовать класс трехмерного вектора, у которого имеются вещественные
координаты x, y, z.
Написать для класса конструкторы :
а) по умолчанию(инициализирует все три координаты нулями)
б) с параметрами(инициализирует все три координаты передаваемыми
значениями)
Написать методы для доступа к полям класса.
Написать метод для установки полей класса.
Написать методы для получения координат с консоли и печати их на консоль :
Read(), Print().
Написать метод, прибавляющий к вектору другой вектор.
Написать метод для нахождения длины вектора : | v | = sqrt(x2 + y2 + z2).
Написать метод для нахождения скалярного произведения двух векторов https ://
ru.wikipedia.org / wiki / Скалярное_произведение
v1*v2 = x1*x2 + y1*y2 + z1*z2.Результатом будет число.
Написать метод для нахождения косинуса угла между векторами через скалярное
произведение : v1*v2 = | v1 | *| v2 | *cos(a).
	Написать метод для нахождения векторного произведения векторов https ://
ru.wikipedia.org / wiki / Векторное_произведение
v3 = v1 x v2.Результатом будет вектор со следующими координатами :
x3 = y1*z2 - z1*y2;
y3 = z1*x2 - x1*z2;
z3 = x1*y2 - y1*x2.*/

#include<iostream>
#include<cstdlib>
#include<cmath>// для pop , sqrt


class Vectors
{
public:

	double x;
	double y;
	double z;
	/*Vectors() : x(0), y(0), z(0)// конструктор а
	{
		std::cout << x << std::endl;// для проверки
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	};*/
	/*Vectors(double m_x, double m_y, double m_z) : x(m_x), y(m_y), z(m_z)//конструктор б 
	{
		
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	};*/
	/*Vectors() // на всякий случай
	{
		std::cin >> x;
		std::cin >> y;
		std::cin >> z;		
	};*/
	void Vectors::set(double x, double y, double z)// установка полей класса
	{
		this->x = x;
		this->y = y;
		this->z = z;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	}

	void Vectors::Read()
	{
		std::cout << "Введите координату x :" << std::endl;
		std::cin >> x;
		std::cout << "Введите координату y :" << std::endl;
		std::cin >> y;
		std::cout << "Введите координату z :" << std::endl;
		std::cin >> z;		
	}

	void Vectors::Print()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	}

	void Vectors::Addition(Vectors obj1, Vectors obj2)//сложение векторов
	{
		x = obj1.x + obj2.x;
		y = obj1.y + obj2.y;
		z = obj1.z + obj2.z;
	}

	double Vectors::length(Vectors obj1)//длина вектора
	{
		double temp;
		temp = sqrt(obj1.x + obj1.y + obj1.z);
		return temp;
	}

	double Vectors::scalar_product(Vectors obj1, Vectors obj2)//скалярное произведение
	{
		double temp;
		temp = obj1.x * obj2.x + obj1.y * obj2.y + obj1.z * obj2.z;
		return temp;
	}

	double Vectors::cosfunc(Vectors a, Vectors b)// косинус угла между векторами
	{
		double temp1;
		double tempa;
		double tempb;
		double result;
		temp1 = a.x * b.x + a.y * b.y + a.x * b.z;
		tempa = sqrt((pow(a.x, a.x) + pow(a.y, a.y) + pow(a.z, a.z)));
		tempb = sqrt((pow(b.x, b.x) + pow(b.y, b.y) + pow(b.z, b.z)));
		result = temp1 / (tempa * tempb);
		return result;
	}
	double Vectors::scalcos(Vectors a, Vectors b)//нахождения косинуса угла между
		                                  //векторами через скалярное произведение
	{
		double temp = a.x * b.x + a.y * b.y + a.z * b.z;
		double temp1 = a.x * b.x + a.y * b.y + a.x * b.z;
		double tempa = sqrt((pow(a.x, a.x) + pow(a.y, a.y) + pow(a.z, a.z)));
		double tempb = sqrt((pow(b.x, b.x) + pow(b.y, b.y) + pow(b.z, b.z)));
		double result = temp1 / (tempa * tempb);
		double scalcos = temp * result;
		return scalcos;
	}
	void Vectors::composition(Vectors a, Vectors b)//векторное произведение векторов
	{
		x = a.y * b.z - a.z * b.y;
		y = a.z * b.x - a.x * b.z;
		z = a.x * b.y - a.y * b.x;
		std::cout << "Координаты вектора :" << std::endl << x << std::endl
			<< y << std::endl << z << std::endl;
	}

};


int main()
{
	system("chcp 1251>nul");
	//Vectors vektor1;
	//Vectors vektor2(12.4, 15.4, 54.2);
	//Vectors vektor3;
	/*std::cout << vektor3.x << std::endl;
	std::cout << vektor3.y << std::endl;
	std::cout << vektor3.z << std::endl;*/
	//vektor3.set(12.34, 22.44, 12.23);
	//vektor3.Read();
	//vektor3.Print();

//***************************сложение векторов************************************
	/*Vectors vektor1;
	Vectors vektor2;
	Vectors vektor3;
	vektor1.Read();
	vektor2.Read();
	vektor3.Addition(vektor1, vektor2);
	vektor3.Print();*/


//*********************длина вектора************************************************

	/*Vectors vektor1;
	vektor1.Read();
	std::cout << "Длина вектора равна: " << vektor1.length(vektor1)
		<< std::endl;*/

//***************************************************

	Vectors vektor1;
	Vectors vektor2;
	Vectors vektor3;
	Vectors asd;
	double test;
	vektor1.Read();
	vektor2.Read();
	std::cout << "Скалярное произведение векторов равно:"
		<< vektor3.scalar_product(vektor1, vektor2) << std::endl;
	std::cout << "Косинус а равно:"
		<< vektor3.cosfunc(vektor1, vektor2) << std::endl;
	test = vektor3.scalcos(vektor1, vektor2);
	std::cout << "косинус угла между векторами через скалярное произведение равен: "
		<< test << std::endl;
	 vektor3.composition(vektor1, vektor2);

	return 0;
}