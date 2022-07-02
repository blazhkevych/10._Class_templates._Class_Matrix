/*
############################################ ЗАДАНИЕ ###########################################
			Шаблонный класс «Матрица»
Реализовать разработанный ранее класс «Матрица» в виде
шаблонного класса. В клиентской части программы
продемонстрировать работу всех методов класса. При создании
объектов шаблонного класса важно типизировать шаблон
разными типами данных (стандартными и пользовательскими).
################################################################################################
		СТАТУС : Не готово.
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

	//// Перегруженный оператор присваивания с копированием.
	Test& operator = (const Test& test);

	// Перегрузка оператора ">" для "this > object".
	bool operator > (const Test& test) const;

	// Перегрузка оператора "*" для "this * object".
	Test operator * (const Test& test) const;

};

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

template <typename T>
T f2()
{
	Matrix<int> obj4_int(3, 3);
	Init(obj4_int);
	cout << "\n\t\t\tMatrix f2() returned obj4_int :";
	cout << obj4_int;
	return obj4_int;
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

	/*
	Не работает !

	// Перегруженный оператор присваивания с переносом.
	// int
	Matrix<int> m6_int(3, 3);
	cout << "\t\t\tm6_int = m2_int = f2();";
	m6_int = m2_int = f2(); // Присваивание с переносом.
	cout << "\t\t\tm6_int:";
	cout << m6_int;
	// double
	Matrix<double> m6_double(3, 3);
	cout << "\t\t\tm6_double = m2_double = f2();";
	m6_double = m2_double = f2(); // Присваивание с переносом.
	cout << "\t\t\tm6_double:";
	cout << m6_double;
	// class Test
	*/


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
	Matrix<int> m12(3, 3);
	Init(m12);
	cout << "\t\t\tm12:";
	cout << m12;
	cout << "\t\t\tm12++;";
	m12++;
	cout << m12;

	// Префиксный декремент.
	Matrix<int> m13(3, 3);
	Init(m13);
	cout << "\t\t\tm13:";
	cout << m13;
	cout << "\t\t\t--m13;";
	--m13;
	cout << m13;

	// Постфиксный декремент.
	Matrix<int> m14(3, 3);
	Init(m14);
	cout << "\t\t\tm14:";
	cout << m14;
	cout << "\t\t\tm14--;";
	m14--;
	cout << m14;

	// Установка / получение значения элемента матрицы.
	Matrix<int> m15(3, 3);
	Init(m15);
	cout << "\t\t\tm15:";
	cout << m15;
	cout << "\t\t\tm15(1, 2) = 999;";
	m15(1, 2) = 999;
	cout << m15;

	// Перегруженный оператор индексации.
	Matrix<int> m16(3, 3);
	Init(m16);
	cout << "\t\t\tm16:";
	cout << m16;
	cout << "\t\t\tm16[1][2] = 999;";
	m16[1][2] = 999;
	cout << m16;

	// Перегруженный оператор <<. Печать матрицы.
	// Перегруженный оператор >>. Ввод данных в матрицу.	
	Matrix<int> m10(3, 3);
	cout << "\t\t\tEnter m10:";
	cin >> m10;
	cout << "\t\t\tm10:";
	cout << m10;

	// Умножение матриц. Ручной ввод.
	Matrix<int> m17(3, 2);
	cout << "\t\t\tEnter m17:";
	cin >> m17;
	//Init(m17);
	cout << "\t\t\tm17:";
	cout << m17;
	Matrix<int> m18(2, 3);
	cout << "\t\t\tEnter m18:";
	cin >> m18;
	//Init(m18);
	cout << "\t\t\tm18:";
	cout << m18;
	cout << "\t\t\tMatrix m19 = m17 * m18;";
	Matrix<int> m19 = m17 * m18;
	cout << m19;
}