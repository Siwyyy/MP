// Siwek Mikolaj

// ReSharper disable CppClangTidyClangDiagnosticInvalidUtf8
// ReSharper disable CppClangTidyClangDiagnosticint32_tEqual
// ReSharper disable StringLiteralTypo
// ReSharper disable IdentifierTypo

// ReSharper disable CppClangTidyModernizeUseNodiscard
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ranges>

class Matrix
{
public:
	Matrix() = delete;
	Matrix(uint16_t width, uint16_t height, bool fill);

	Matrix operator +(Matrix addend) const;
	Matrix operator *(Matrix factor) const;

	void writeInto() const;
	void print() const;
	Matrix transposed() const;

	static void printAddition(const Matrix& addend_left, const Matrix& addend_right, const Matrix& sum);
	static void printMultiplication(const Matrix& factor_left, const Matrix& factor_right, const Matrix& product);
	static void printTransposition(const Matrix& original, const Matrix& transpose);

private:
	const uint16_t m_width, m_height;
	int32_t** m_values;

	inline static uint16_t max_value_lenght = 0;

	static void recalcMaxValueLenght(int32_t value);
};

Matrix::Matrix(const uint16_t width, const uint16_t height, const bool fill)
	: m_width(width),
	  m_height(height)
{
	m_values = new int32_t*[m_height];
	for (int i = 0; i < m_height; i++)
	{
		m_values[i] = new int32_t[m_width];
		for (int j = 0; j < m_width; j++)
			m_values[i][j] = std::numeric_limits<int32_t>::min();
	}

	if (fill)
		writeInto();
}

Matrix Matrix::operator+(const Matrix addend) const
{
	const Matrix sum(m_width, m_height, false);
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
		{
			sum.m_values[i][j] = m_values[i][j] + addend.m_values[i][j];
			recalcMaxValueLenght(sum.m_values[i][j]);
		}

	return sum;
}

Matrix Matrix::operator*(const Matrix factor) const
{
	const Matrix product(factor.m_width, m_height, false);
	for (int i = 0; i < product.m_height; i++)
	{
		for (int j = 0; j < product.m_width; j++)
		{
			int32_t sum = 0;
			for (int k = 0; k < m_width; k++)
			{
				sum += m_values[i][k] * factor.m_values[k][j];
			}
			product.m_values[i][j] = sum;
			recalcMaxValueLenght(sum);
		}
	}
	return product;
}

void Matrix::writeInto() const
{
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
		{
			m_values[i][j] = std::numeric_limits<int32_t>::max();
			system("cls");
			print();
			std::cout << "Podaj wartosc elementu [" << i << "," << j << "]: ";
			std::cin >> m_values[i][j];
			recalcMaxValueLenght(m_values[i][j]);
		}
}

void Matrix::print() const
{
	for (int i = 0; i < m_height; i++)
	{
		std::cout << '|' << ' ';
		for (int j = 0; j < m_width; j++)
			if (m_values[i][j] == std::numeric_limits<int32_t>::max())
				std::cout << std::setw(max_value_lenght) << '_' << ' ';
			else if (m_values[i][j] == std::numeric_limits<int32_t>::min())
				std::cout << std::setw(max_value_lenght) << ' ' << ' ';
			else
				std::cout << std::setw(max_value_lenght) << m_values[i][j] << ' ';
		std::cout << "|\n";
	}
}

Matrix Matrix::transposed() const
{
	const Matrix transpose(m_height, m_width, false);
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
			transpose.m_values[j][i] = m_values[i][j];
	return transpose;
}

void Matrix::printAddition(const Matrix& addend_left, const Matrix& addend_right, const Matrix& sum)
{
	system("cls");
	for (int i = 0; i < addend_left.m_height; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < addend_left.m_width; j++)
			std::cout << std::setw(max_value_lenght) << addend_left.m_values[i][j] << ' ';
		std::cout << "| " << (i == addend_left.m_height / 2 ? '+' : ' ') << " | ";
		for (int j = 0; j < addend_right.m_width; j++)
			std::cout << std::setw(max_value_lenght) << addend_right.m_values[i][j] << ' ';
		std::cout << "| " << (i == addend_left.m_height / 2 ? '=' : ' ') << " | ";
		for (int j = 0; j < sum.m_width; j++)
			std::cout << std::setw(max_value_lenght) << sum.m_values[i][j] << ' ';
		std::cout << "|\n";
	}
}

void Matrix::printMultiplication(const Matrix& factor_left, const Matrix& factor_right, const Matrix& product)
{
	system("cls");
	for (int i = 0; i < factor_right.m_height; i++)
	{
		std::cout << std::setw(factor_left.m_width * (max_value_lenght + 1) + 4) << ' ' << "| ";
		for (int j = 0; j < factor_right.m_width; j++)
			std::cout << std::setw(max_value_lenght) << factor_right.m_values[i][j] << ' ';
		std::cout << "|\n";
	}
	std::cout << '\n';
	for (int i = 0; i < factor_left.m_height; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < factor_left.m_width; j++)
			std::cout << std::setw(max_value_lenght) << factor_left.m_values[i][j] << ' ';
		std::cout << "| | ";
		for (int j = 0; j < product.m_width; j++)
			std::cout << std::setw(max_value_lenght) << product.m_values[i][j] << ' ';
		std::cout << "|\n";
	}
}

void Matrix::printTransposition(const Matrix& original, const Matrix& transpose)
{
	system("cls");
	for (int i = 0; i < original.m_height; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < original.m_width; j++)
			std::cout << std::setw(max_value_lenght) << original.m_values[i][j] << ' ';
		std::cout << "|\n";
	}
	for (int i = 0; i < transpose.m_height; i++)
	{
		std::cout << std::setw(original.m_width * (max_value_lenght + 1) + 2) << ' ' << "| ";
		for (int j = 0; j < transpose.m_width; j++)
			std::cout << std::setw(max_value_lenght) << transpose.m_values[i][j] << ' ';
		std::cout << "|\n";
	}
}

void Matrix::recalcMaxValueLenght(int32_t value)
{
	uint16_t value_lenght = 0;
	if (value < 0) value_lenght++;
	while (value)
	{
		value_lenght++;
		value /= 10;
	}
	if (value_lenght > max_value_lenght)
		max_value_lenght = value_lenght;
}

void addition()
{
	uint16_t width, height;
	std::cout << "Podaj rozmiar macierzy\n";
	std::cout << "Szerokosc: ";
	std::cin >> width;
	std::cout << "Wysokosc: ";
	std::cin >> height;
	const Matrix* matrix_left = new Matrix(width, height, true);
	const Matrix* matrix_right = new Matrix(width, height, true);
	const Matrix* matrix_sum = new const Matrix(*matrix_left + *matrix_right);
	Matrix::printAddition(*matrix_left, *matrix_right, *matrix_sum);
}

void multiplication()
{
	uint16_t left_width, common_dimension, right_height;
	std::cout << "Podaj rozmiar macierzy\n";
	std::cout << "Szerokosc lewej: ";
	std::cin >> left_width;
	std::cout << "Wysokosc lewej/szerokosc prawej: ";
	std::cin >> common_dimension;
	std::cout << "Wysokosc prawej: ";
	std::cin >> right_height;
	const Matrix* matrix_left = new Matrix(left_width, common_dimension, true);
	const Matrix* matrix_right = new Matrix(common_dimension, right_height, true);
	const Matrix* martix_product = new Matrix(*matrix_left * *matrix_right);
	Matrix::printMultiplication(*matrix_left, *matrix_right, *martix_product);
}

void transposition()
{
	uint16_t width, height;
	std::cout << "Podaj rozmiar macierzy\n";
	std::cout << "Szerokosc: ";
	std::cin >> width;
	std::cout << "Wysokosc: ";
	std::cin >> height;
	const Matrix* matrix = new Matrix(width, height, true);
	const Matrix* transpose = new Matrix(matrix->transposed());
	Matrix::printTransposition(*matrix, *transpose);
}

int main()
{
	std::cout << "== == MENU == ==\n";
	std::cout << "[1] Dodawanie macierzy\n";
	std::cout << "[2] Mnozenie macierzy\n";
	std::cout << "[3] Transpozycja macierzy\n";
	std::cout << "== == ==== == ==\n";

	char opcja;
	do
		opcja = _getch();
	while (opcja != '1' && opcja != '2' && opcja != '3' && opcja != '4' && opcja != 'q');

	switch (opcja)
	{
	case '1':
		addition();
		break;
	case '2':
		multiplication();
		break;
	case '3':
		transposition();
		break;
	default:
		break;
	}


	return 0;
}
