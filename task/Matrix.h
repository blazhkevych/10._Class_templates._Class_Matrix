#pragma once
#include <iostream>
#include <ostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class Matrix
{
	// Указатель на двумерный динамический массив.
	T** m_p;
	// Количество строк, количество столбцов.
	int m_row, m_col;
public:
	Matrix();											// Конструктор по умолчанию.
	Matrix(int row, int col);							// Конструктор с 2 параметрами.
	Matrix(const Matrix& matrix);						// Конструктор копирования.
	Matrix(Matrix&& matrix);							// Конструктор переноса.
	~Matrix();											// Деструктор.
	Matrix<T>& operator = (const Matrix& matrix);		// Перегруженный оператор присваивания с копированием.
	Matrix<T>& operator = (Matrix&& matrix);			// Перегруженный оператор присваивания с переносом.

	//// Увеличение на 1 каждого элемента матрицы:
	Matrix<T>& operator ++();							// Префиксный инкремент.
	Matrix<T> operator ++(int);							// Постфиксный инкремент.

	//// Уменьшение на 1 каждого элемента матрицы:
	Matrix<T>& operator --();							// Префиксный декремент.
	Matrix<T> operator --(int);							// Постфиксный декремент.
	Matrix<T> operator+(const Matrix& matrix) const;	// Сложение матриц.
	Matrix operator*(const Matrix& matrix) const;		// Умножение матриц.
	int& operator()(int row, int col);					// Установка / получение значения элемента матрицы.	
	int*& operator [] (int index);						// Перегруженный оператор индексации.

	// Перегруженный оператор <<. Печать матрицы.
	template<typename T>
	friend ostream& operator << (ostream& cout, Matrix<T>& matrix);

	// Перегруженный оператор >>. Ввод данных в матрицу.
	template<typename T>
	friend istream& operator >> (istream& cin, Matrix<T>& matrix);

	// Функция автоматической инициализации массива.
	template<typename T>
	friend Matrix<T>& Init(Matrix<T>& matrix);
};

///////////////////////////////////////////////
///Реализация шаблонных методов класса Matrix//
///////////////////////////////////////////////

// Конструктор по умолчанию.
template<typename T>
Matrix<T>::Matrix() :m_p{ nullptr }, m_row{ 0 }, m_col(0){};
//{
//	m_p = nullptr;
//	m_row = 0;
//	m_col = 0;
//}

// Конструктор с 2 параметрами.
template<typename T>
Matrix<T>::Matrix(int row, int col) :m_row{ row }, m_col(col)
{
	/*m_row = row;
	m_col = col;*/
	m_p = new T * [m_row]();
	for (int i = 0; i < m_row; i++)
		m_p[i] = new T[m_col]();
}

//Конструктор копирования.
template<typename T>
Matrix<T>::Matrix(const Matrix& matrix) :m_row{ matrix.m_row }, m_col{ matrix.m_col }
{
	/*m_row = matrix.m_row;
	m_col = matrix.m_col;*/
	m_p = new T * [m_row];
	for (int i = 0; i < m_row; i++)
		m_p[i] = new T[m_col];

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] = matrix.m_p[i][j];
		}
	}
}

// Реализация семантики переноса с использованием r-value ссылок.
// Конструктор переноса.
template<typename T>
Matrix<T>::Matrix(Matrix&& matrix)
	: m_p{ matrix.m_p }, m_row{ matrix.m_row }, m_col{ matrix.m_col }
{
	// Присваивание.
	/*m_p = matrix.m_p;
	m_row = matrix.m_row;
	m_col = matrix.m_col;*/

	// Обнуление matrix.	
	matrix.m_p = nullptr;
	matrix.m_row = 0;
	matrix.m_col = 0;
}

// Деструктор.
template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < m_row; i++)
		delete[] m_p[i];
	delete[] m_p;
}

// Перегруженный оператор присваивания с копированием.
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& matrix)
{
	if (this == &matrix) // Если самоприсваивание.
		return *this;

	for (int i = 0; i < m_row; i++) // Очистка принимающего обьекта.
		delete[] m_p[i];
	delete[] m_p;

	m_p = new T * [matrix.m_row]; // Выделение памяти под входящий обьект.
	for (int i = 0; i < matrix.m_row; i++)
		m_p[i] = new T[matrix.m_col];

	// Копируем данные из входящего обьекта в принимающий.
	m_row = matrix.m_row;
	m_col = matrix.m_col;
	for (int i = 0; i < m_row; ++i)
		for (int j = 0; j < m_col; j++)
			m_p[i][j] = matrix.m_p[i][j];

	return *this;
}

// Перегруженный оператор присваивания с переносом.
template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& matrix)
{
	if (this == &matrix) // Если самоприсваивание.
		return *this;

	for (int i = 0; i < m_row; i++) // Очистка принимающего обьекта.
		delete[] m_p[i];
	delete[] m_p;

	// Присваивание.
	m_p = matrix.m_p;
	m_row = matrix.m_row;
	m_col = matrix.m_col;

	// Обнуление matrix.	
	matrix.m_p = nullptr;
	matrix.m_row = 0;
	matrix.m_col = 0;

	return *this;
}

// Префиксный инкремент.
template<typename T>
Matrix<T>& Matrix<T>::operator++()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] ++;
		}
	}
	return *this;
}

// Постфиксный инкремент.
template<typename T>
Matrix<T> Matrix<T>::operator++(int)
{
	Matrix tmp = *this;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] ++;
		}
	}
	return tmp;
}

// Префиксный декремент.
template<typename T>
Matrix<T>& Matrix<T>::operator--()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] --;
		}
	}
	return *this;
}

// Постфиксный декремент.
template<typename T>
Matrix<T> Matrix<T>::operator--(int)
{
	Matrix tmp = *this;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] --;
		}
	}
	return tmp;
}

// Сложение матриц.
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& matrix) const
{
	Matrix<T> result(matrix.m_row, matrix.m_col); // Если матрицы одинаковые, выполняем сложение.
	if (m_row == matrix.m_row && m_col == matrix.m_col)
	{
		// Копирование данных из matrix в новый массив.
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				result.m_p[i][j] = this->m_p[i][j] + matrix.m_p[i][j];
	}
	else // Если разные, возвращаем переданную сюда матрицу.
	{
		return matrix;
	}

	return result;
}

// Умножение матриц.
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& matrix) const
{
	Matrix<T> result(m_row, matrix.m_col);

	if (m_col == matrix.m_row)
	{
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < matrix.m_col; j++)
			{
				for (int q = 0; q < m_col; q++)
				{
					result[i][j] += m_p[i][q] * matrix.m_p[q][j];
				}
			}
		}
	}
	else // Иначе, возвращаем переданную сюда матрицу.
	{
		return matrix;
	}

	return result;
}

// Установка / получение значения элемента матрицы.
template<typename T>
int& Matrix<T>::operator()(int row, int col)
{
	return m_p[row][col];
}

// Перегруженный оператор индексации.
template<typename T>
int*& Matrix<T>::operator[](int index)
{
	if (index < 0 || index >= m_row)
		return m_p[0]; // Не лучшее решение, но пока так.
	return m_p[index];
}

// Перегруженный оператор <<. Печать матрицы.
template<typename T>
ostream& operator<<(ostream& cout, Matrix<T>& matrix)
{
	cout << endl;
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_col; j++)
		{
			cout << matrix.m_p[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	return cout;
}

// Перегруженный оператор >>. Ввод данных в матрицу.
template<typename T>
istream& operator>>(istream& cin, Matrix<T>& matrix)
{
	cout << endl;
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_col; j++)
			cin >> matrix.m_p[i][j];
	}
	cout << endl;

	return cin;
}

// Функция автоматической инициализации массива.
template<typename T>
Matrix<T>& Init(Matrix<T>& matrix)
{
	int min = 10; // Минимальное значение.
	int max = 99; // Максимальное значение.
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_col; j++)
			matrix.m_p[i][j] = (rand() % (max - min + 1) + min) * 0.99; // Заполняет массив псевдослучайными числами.
	}
	return matrix;
}