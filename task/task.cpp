/*
############################################ ЗАДАНИЕ ###########################################
			Шаблонный класс «Матрица»
Реализовать разработанный ранее класс «Матрица» в виде
шаблонного класса. В клиентской части программы
продемонстрировать работу всех методов класса. При создании
объектов шаблонного класса важно типизировать шаблон
разными типами данных (стандартными и пользовательскими).
################################################################################################
		СТАТУС : Готово.
		ДОРАБОТКИ:
*
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
*
		ВОПРОСЫ:
*
		ВИДЕО: 02:36:18 (начало дз), 01:43:00(шаблоны класса), 02:05:40 (о шаблонном веркторе)
################################################################################################
*/

#include <iostream>
#include "Matrix.h"

class Test
{
	int m_a;
public:
	Test() :m_a{ 0 } {};
	Test(int a) :m_a{ a } {};

	void Set(int n)
	{
		m_a = n;
	}
	int Get()
	{
		return m_a;
	}
	void Show()
	{
		cout << m_a << endl;
	}

	friend ostream& operator<<(ostream& os, const Test& obj);
	friend istream& operator>>(istream& os, Test& obj);

	Test operator + (const Test& test) const;

	Test operator - (const Test& test) const;

	// Увеличение всех компонент вектора на единицу (префикс).	
	Test& operator ++ ();

	// Увеличение всех компонент вектора на единицу (постфикс).	
	Test operator ++ (int postfix);

	// Уменьшение всех компонент вектора на	единицу (префикс).
	Test& operator--();

	// Уменьшение всех компонент вектора на единицу (постфикс).
	Test operator--(int postfix);

	// Перегруженный оператор присваивания с копированием.
	Test& operator = (const Test& test);


	// Перегруженный оператор += для сложения двух Test.
	Test& operator+=(const Test& test);

	// Перегрузка оператора ">" для "this > object".
	bool operator > (const Test& test) const;

	// Перегрузка оператора "*" для "this * object".
	Test operator * (const Test& test) const;

};

Test& Test::operator+=(const Test& test)
{
	*this = this->operator+(test);

	return *this;
}

ostream& operator<<(ostream& os, const Test& obj)
{
	cout << obj.m_a << "\t";
	return os;
}

istream& operator>>(istream& is, Test& obj)
{
	cin >> obj.m_a;
	return is;
}

Test Test::operator+(const Test& test) const
{
	Test result{};
	result.m_a = m_a + test.m_a;
	return result;
}

Test Test::operator-(const Test& test) const
{
	Test result{};
	result.m_a = m_a - test.m_a;
	return result;
}

Test& Test::operator++()
{
	++m_a;
	return *this;
}

Test Test::operator++(int postfix)
{
	Test tmp = *this;
	m_a++;
	return tmp;
}

Test& Test::operator--()
{
	--m_a;
	return *this;
}

Test Test::operator--(int postfix)
{
	Test tmp = *this;
	m_a--;
	return tmp;
}

Test& Test::operator=(const Test& test)
{
	if (this == &test)
		return *this;
	m_a = test.m_a;

	return *this;
}

bool Test::operator>(const Test& test) const
{
	return m_a > test.m_a ? m_a : test.m_a;
}

Test Test::operator*(const Test& test) const
{
	Test result{};
	result.m_a = m_a * test.m_a;
	return result;
}

Matrix<int> function_int()
{
	Matrix<int> obj4_int(3, 3);
	Init(obj4_int);
	cout << "\n\t\t\tMatrix function_int() returned obj4_int :";
	cout << obj4_int;
	return obj4_int;
}

Matrix<double> function_double()
{
	Matrix<double> obj4_double(3, 3);
	Init(obj4_double);
	cout << "\n\t\t\tMatrix function_double() returned obj4_double :";
	cout << obj4_double;
	return obj4_double;
}

Matrix<Test> function_class()
{
	Matrix<Test> obj4_class(3, 3);
	Init(obj4_class);
	cout << "\n\t\t\tMatrix function_class() returned obj4_class :";
	cout << obj4_class;
	return obj4_class;
}

int main()
{
	srand(time(0));

	// Конструктор по умолчанию.
	// int
	Matrix<int> m0_int;
	// double
	Matrix<double> m0_double;
	// class Test
	Matrix<Test> m0_class;

	// Конструктор с 2 параметрами.
	// int
	Matrix<int> m1_int(3, 3);
	Init(m1_int);
	cout << "\t\t\tm1_int:";
	cout << m1_int;
	// double
	Matrix<double> m1_double(3, 3);
	Init(m1_double);
	cout << "\t\t\tm1_double:";
	cout << m1_double;
	// class Test
	Matrix<Test> m1_class(3, 3);
	Init(m1_class);
	cout << "\t\t\tm1_class:";
	cout << m1_class;

	// Конструктор с 2 параметрами.
	// int
	Matrix<int> m2_int(3, 3);
	Init(m2_int);
	cout << "\t\t\tm2_int:";
	cout << m2_int;
	// double
	Matrix<double> m2_double(3, 3);
	Init(m2_double);
	cout << "\t\t\tm2_double:";
	cout << m2_double;
	// class Test
	Matrix<Test> m2_class(3, 3);
	Init(m2_class);
	cout << "\t\t\tm2_class:";
	cout << m2_class;

	//Конструктор копирования.
	// int
	Matrix<int> m3_int = m1_int;
	cout << "\t\t\tMatrix m3_int = m1_int;";
	cout << m3_int;
	// double
	Matrix<double> m3_double = m1_double;
	cout << "\t\t\tMatrix m3_double = m1_double;";
	cout << m3_double;
	// class Test
	Matrix<Test> m3_class = m1_class;
	cout << "\t\t\tMatrix m3_class = m1_class;";
	cout << m3_class;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	// Сложение матриц.
	// int
	Matrix<int> m4_int = m1_int + m2_int; // Конструктор переноса.
	cout << "\t\t\tMatrix m4_int = m1_int + m2_int;";
	cout << m4_int;
	// double
	Matrix<double> m4_double = m1_double + m2_double; // Конструктор переноса.
	cout << "\t\t\tMatrix m4_double = m1_double + m2_double;";
	cout << m4_double;
	// class Test
	Matrix<Test> m4_class = m1_class + m2_class; // Конструктор переноса.
	cout << "\t\t\tMatrix m4_class = m1_class + m2_class;";
	cout << m4_class;

	// Перегруженный оператор присваивания с копированием.
	// int
	Matrix<int> m5_int(3, 3);
	Init(m5_int);
	cout << "\t\t\tm5_int:";
	cout << m5_int;
	cout << "\t\t\tm5_int = m4_int;";
	m5_int = m4_int; // Присваивание с копированием.
	cout << m5_int;
	// double
	Matrix<double> m5_double(3, 3);
	Init(m5_double);
	cout << "\t\t\tm5_double:";
	cout << m5_double;
	cout << "\t\t\tm5_double = m4_double;";
	m5_double = m4_double; // Присваивание с копированием.
	cout << m5_double;
	// class Test
	Matrix<Test> m5_class(3, 3);
	Init(m5_class);
	cout << "\t\t\tm5_class:";
	cout << m5_class;
	cout << "\t\t\tm5_class = m4_class;";
	m5_class = m4_class; // Присваивание с копированием.
	cout << m5_class;

	// Перегруженный оператор присваивания с переносом.
	// int
	Matrix<int> m6_int(3, 3);
	cout << "\t\t\tm6_int = m2_int = function_int();";
	m6_int = m2_int = function_int(); // Присваивание с переносом.
	cout << "\t\t\tm6_int:";
	cout << m6_int;
	// double
	Matrix<double> m6_double(3, 3);
	cout << "\t\t\tm6_double = m2_double = function_double();";
	m6_double = m2_double = function_double(); // Присваивание с переносом.
	cout << "\t\t\tm6_double:";
	cout << m6_double;
	// class Test
	Matrix<Test> m6_class(3, 3);
	cout << "\t\t\tm6_class = m2_class = function_class();";
	m6_class = m2_class = function_class(); // Присваивание с переносом.
	cout << "\t\t\tm6_class:";
	cout << m6_class;

	// Умножение матриц.
	// int
	Matrix<int> m7_int(3, 3);
	Init(m7_int);
	cout << "\t\t\tm7_int:";
	cout << m7_int;
	Matrix<int> m8_int(3, 3);
	Init(m8_int);
	cout << "\t\t\tm8_int:";
	cout << m8_int;
	Matrix<int> m9_int(3, 3);
	Init(m9_int);
	cout << "\t\t\tm9_int:";
	cout << m9_int;
	cout << "\t\t\tm9_int = m7_int * m8_int;";
	m9_int = m7_int * m8_int;
	cout << m9_int;
	// double
	Matrix<double> m7_double(3, 3);
	Init(m7_double);
	cout << "\t\t\tm7_double:";
	cout << m7_double;
	Matrix<double> m8_double(3, 3);
	Init(m8_double);
	cout << "\t\t\tm8_double:";
	cout << m8_double;
	Matrix<double> m9_double(3, 3);
	Init(m9_double);
	cout << "\t\t\tm9_double:";
	cout << m9_double;
	cout << "\t\t\tm9_double = m7_double * m8_double;";
	m9_double = m7_double * m8_double;
	cout << m9_double;
	// class Test
	Matrix<Test> m7_class(3, 3);
	Init(m7_class);
	cout << "\t\t\tm7_class:";
	cout << m7_class;
	Matrix<Test> m8_class(3, 3);
	Init(m8_class);
	cout << "\t\t\tm8_class:";
	cout << m8_class;
	Matrix<Test> m9_class(3, 3);
	Init(m9_class);
	cout << "\t\t\tm9_class:";
	cout << m9_class;
	cout << "\t\t\tm9_class = m7_class * m8_class;";
	m9_class = m7_class * m8_class;
	cout << m9_class;

	// Префиксный инкремент.
	// int
	Matrix<int> m11_int(3, 3);
	Init(m11_int);
	cout << "\t\t\tm11_int:";
	cout << m11_int;
	cout << "\t\t\t++m11_int;";
	++m11_int;
	cout << m11_int;
	// double
	Matrix<double> m11_double(3, 3);
	Init(m11_double);
	cout << "\t\t\tm11_double:";
	cout << m11_double;
	cout << "\t\t\t++m11_double;";
	++m11_double;
	cout << m11_double;
	// class Test
	Matrix<Test> m11_class(3, 3);
	Init(m11_class);
	cout << "\t\t\tm11_class:";
	cout << m11_class;
	cout << "\t\t\t++m11_class;";
	++m11_class;
	cout << m11_class;

	// Постфиксный инкремент.
	// int
	Matrix<int> m12_int(3, 3);
	Init(m12_int);
	cout << "\t\t\tm12_int:";
	cout << m12_int;
	cout << "\t\t\tm12_int++;";
	m12_int++;
	cout << m12_int;
	// double
	Matrix<double> m12_double(3, 3);
	Init(m12_double);
	cout << "\t\t\tm12_double:";
	cout << m12_double;
	cout << "\t\t\tm12_double++;";
	m12_double++;
	cout << m12_double;
	// class Test
	Matrix<Test> m12_class(3, 3);
	Init(m12_class);
	cout << "\t\t\tm12_class:";
	cout << m12_class;
	cout << "\t\t\tm12_class++;";
	m12_class++;
	cout << m12_class;

	// Префиксный декремент.
	// int
	Matrix<int> m13_int(3, 3);
	Init(m13_int);
	cout << "\t\t\tm13_int:";
	cout << m13_int;
	cout << "\t\t\t--m13_int;";
	--m13_int;
	cout << m13_int;
	// double
	Matrix<double> m13_double(3, 3);
	Init(m13_double);
	cout << "\t\t\tm13_double:";
	cout << m13_double;
	cout << "\t\t\t--m13_double;";
	--m13_double;
	cout << m13_double;
	// class Test
	Matrix<Test> m13_class(3, 3);
	Init(m13_class);
	cout << "\t\t\tm13_class:";
	cout << m13_class;
	cout << "\t\t\t--m13_class;";
	--m13_class;
	cout << m13_class;

	// Постфиксный декремент.
	// int
	Matrix<int> m14_int(3, 3);
	Init(m14_int);
	cout << "\t\t\tm14_int:";
	cout << m14_int;
	cout << "\t\t\tm14_int--;";
	m14_int--;
	cout << m14_int;
	// double
	Matrix<double> m14_double(3, 3);
	Init(m14_double);
	cout << "\t\t\tm14_double:";
	cout << m14_double;
	cout << "\t\t\tm14_double--;";
	m14_double--;
	cout << m14_double;
	// class Test
	Matrix<Test> m14_class(3, 3);
	Init(m14_class);
	cout << "\t\t\tm14_class:";
	cout << m14_class;
	cout << "\t\t\tm14_class--;";
	m14_class--;
	cout << m14_class;

	// Установка / получение значения элемента матрицы.
	// int
	Matrix<int> m15_int(3, 3);
	Init(m15_int);
	cout << "\t\t\tm15:";
	cout << m15_int;
	cout << "\t\t\tm15(1, 2) = 999;";
	m15_int(1, 2) = 999;
	cout << m15_int;
	// double
	Matrix<double> m15_double(3, 3);
	Init(m15_double);
	cout << "\t\t\tm15_double:";
	cout << m15_double;
	cout << "\t\t\tm15_double(1, 2) = 999;";
	m15_double(1, 2) = 999;
	cout << m15_double;
	// class Test
	Matrix<Test> m15_class(3, 3);
	Init(m15_class);
	cout << "\t\t\tm15_class:";
	cout << m15_class;
	cout << "\t\t\tm15_class(1, 2) = 999;";
	m15_class(1, 2) = 999;
	cout << m15_class;

	// Перегруженный оператор индексации.
	// int
	Matrix<int> m16_int(3, 3);
	Init(m16_int);
	cout << "\t\t\tm16_int:";
	cout << m16_int;
	cout << "\t\t\tm16_int[1][2] = 999;";
	m16_int[1][2] = 999;
	cout << m16_int;
	// double
	Matrix<double> m16_double(3, 3);
	Init(m16_double);
	cout << "\t\t\tm16_double:";
	cout << m16_double;
	cout << "\t\t\tm16_double[1][2] = 999;";
	m16_double[1][2] = 999;
	cout << m16_double;
	// class Test
	Matrix<Test> m16_class(3, 3);
	Init(m16_class);
	cout << "\t\t\tm16_class:";
	cout << m16_class;
	cout << "\t\t\tm16_class[1][2] = 999;";
	m16_class[1][2] = 999;
	cout << m16_class;

	// Перегруженный оператор <<. Печать матрицы.
	// Перегруженный оператор >>. Ввод данных в матрицу.
	// int
	Matrix<int> m10_int(3, 3);
	cout << "\t\t\tEnter m10_int:";
	cin >> m10_int;
	cout << "\t\t\tm10_int:";
	cout << m10_int;
	// double
	Matrix<double> m10_double(3, 3);
	cout << "\t\t\tEnter m10_double:";
	cin >> m10_double;
	cout << "\t\t\tm10_double:";
	cout << m10_double;
	// class Test
	Matrix<Test> m10_class(3, 3);
	cout << "\t\t\tEnter m10_class:";
	cin >> m10_class;
	cout << "\t\t\tm10_class:";
	cout << m10_class;

	// Умножение матриц. Ручной ввод.
	// int
	Matrix<int> m17_int(3, 2);
	cout << "\t\t\tEnter m17_int:";
	cin >> m17_int;
	//Init(m17_int);
	cout << "\n\t\t\tm17_int:";
	cout << m17_int;
	Matrix<int> m18_int(2, 3);
	cout << "\t\t\tEnter m18_int:";
	cin >> m18_int;
	//Init(m18_int);
	cout << "\n\t\t\tm18_int:";
	cout << m18_int;
	cout << "\t\t\tMatrix m19_int = m17_int * m18_int;";
	Matrix<int> m19_int = m17_int * m18_int;
	cout << m19_int;
	// double
	Matrix<double> m17_double(3, 2);
	cout << "\t\t\tEnter m17_double:";
	cin >> m17_double;
	//Init(m17_double);
	cout << "\n\t\t\tm17_double:";
	cout << m17_double;
	Matrix<double> m18_double(2, 3);
	cout << "\t\t\tEnter m18_double:";
	cin >> m18_double;
	//Init(m18_double);
	cout << "\n\t\t\tm18_double:";
	cout << m18_double;
	cout << "\t\t\tMatrix m19_double = m17_double * m18_double;";
	Matrix<double> m19_double = m17_double * m18_double;
	cout << m19_double;
	// class Test
	Matrix<Test> m17_class(3, 2);
	cout << "\t\t\tEnter m17_class:";
	cin >> m17_class;
	//Init(m17_class);
	cout << "\n\t\t\tm17_class:";
	cout << m17_class;
	Matrix<Test> m18_class(2, 3);
	cout << "\t\t\tEnter m18_class:";
	cin >> m18_class;
	//Init(m18_class);
	cout << "\n\t\t\tm18_class:";
	cout << m18_class;
	cout << "\t\t\tMatrix m19_class = m17_class * m18_class;";
	Matrix<Test> m19_class = m17_class * m18_class;
	cout << m19_class;
}