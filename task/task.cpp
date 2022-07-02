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
	//Test& operator = (const Test& test);

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

Matrix f2()
{
	Matrix obj4(3, 3);
	Init(obj4);
	cout << "\n\t\t\tMatrix f2() returned obj4 :";
	cout << obj4;
	return obj4;
}

int main()
{
	srand(time(0));

	// Конструктор по умолчанию.
	Matrix m0;

	// Конструктор с 2 параметрами.
	Matrix m1(3, 3);
	Init(m1);
	cout << "\t\t\tm1:";
	cout << m1;

	// Конструктор с 2 параметрами.
	Matrix m2(3, 3);
	Init(m2);
	cout << "\t\t\tm2:";
	cout << m2;

	//Конструктор копирования.
	Matrix m3 = m1;
	cout << "\t\t\tMatrix m3 = m1;";
	cout << m3;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	// Сложение матриц.
	Matrix m4 = m1 + m2; // Конструктор переноса.
	cout << "\t\t\tMatrix m4 = m1 + m2;";
	cout << m4;

	// Перегруженный оператор присваивания с копированием.
	Matrix m5(3, 3);
	Init(m5);
	cout << "\t\t\tm5:";
	cout << m5;
	cout << "\t\t\tm5 = m4;";
	m5 = m4; // Присваивание с копированием.
	cout << m5;

	// Перегруженный оператор присваивания с переносом.
	Matrix m6(3, 3);
	cout << "\t\t\tm6 = m2 = f2();";
	m6 = m2 = f2(); // Присваивание с переносом.
	cout << "\t\t\tm6:";
	cout << m6;

	// Умножение матриц.
	Matrix m7(3, 3);
	Init(m7);
	cout << "\t\t\tm7:";
	cout << m7;
	Matrix m8(3, 3);
	Init(m8);
	cout << "\t\t\tm8:";
	cout << m8;
	Matrix m9(3, 3);
	Init(m9);
	cout << "\t\t\tm9:";
	cout << m9;
	cout << "\t\t\tm9 = m7 * m8;";
	m9 = m7 * m8;
	cout << m9;

	// Префиксный инкремент.
	Matrix m11(3, 3);
	Init(m11);
	cout << "\t\t\tm11:";
	cout << m11;
	cout << "\t\t\t++m11;";
	++m11;
	cout << m11;

	// Постфиксный инкремент.
	Matrix m12(3, 3);
	Init(m12);
	cout << "\t\t\tm12:";
	cout << m12;
	cout << "\t\t\tm12++;";
	m12++;
	cout << m12;

	// Префиксный декремент.
	Matrix m13(3, 3);
	Init(m13);
	cout << "\t\t\tm13:";
	cout << m13;
	cout << "\t\t\t--m13;";
	--m13;
	cout << m13;

	// Постфиксный декремент.
	Matrix m14(3, 3);
	Init(m14);
	cout << "\t\t\tm14:";
	cout << m14;
	cout << "\t\t\tm14--;";
	m14--;
	cout << m14;

	// Установка / получение значения элемента матрицы.
	Matrix m15(3, 3);
	Init(m15);
	cout << "\t\t\tm15:";
	cout << m15;
	cout << "\t\t\tm15(1, 2) = 999;";
	m15(1, 2) = 999;
	cout << m15;

	// Перегруженный оператор индексации.
	Matrix m16(3, 3);
	Init(m16);
	cout << "\t\t\tm16:";
	cout << m16;
	cout << "\t\t\tm16[1][2] = 999;";
	m16[1][2] = 999;
	cout << m16;

	// Перегруженный оператор <<. Печать матрицы.
	// Перегруженный оператор >>. Ввод данных в матрицу.	
	Matrix m10(3, 3);
	cout << "\t\t\tEnter m10:";
	cin >> m10;
	cout << "\t\t\tm10:";
	cout << m10;

	// Умножение матриц. Ручной ввод.
	Matrix m17(3, 2);
	cout << "\t\t\tEnter m17:";
	cin >> m17;
	//Init(m17);
	cout << "\t\t\tm17:";
	cout << m17;
	Matrix m18(2, 3);
	cout << "\t\t\tEnter m18:";
	cin >> m18;
	//Init(m18);
	cout << "\t\t\tm18:";
	cout << m18;
	cout << "\t\t\tMatrix m19 = m17 * m18;";
	Matrix m19 = m17 * m18;
	cout << m19;
}