#pragma once
#include "includes.h"

//  ***************************
//  *   OPERATORS OVERRIDES   *
//  ***************************

// Matrix + Matrix = Matrix
inline Matrix& operator + (Matrix& m1, Matrix& m2)
{
	Matrix error = Matrix(1);
	if (m1.Height() != m2.Height() || m1.Width() != m2.Width()) // If matrixes are not the same size - they can`t be added
		return error;

	Matrix result(m1.Width(), m1.Height());
	for (size_t j = 0; j < result.Height(); j++)
	{
		for (size_t i = 0; i < result.Width(); i++)
		{
			result(i, j) = m1(i, j) + m2(i, j);
		}
	}

	return result;
}

// Matrix - Matrix = Matrix
inline Matrix& operator - (Matrix& m1, Matrix& m2)
{
	Matrix error = Matrix(1);
	if (m1.Height() != m2.Height() || m1.Width() != m2.Width()) // If matrixes are not the same size - they can`t be taken away
		return error;

	Matrix result(m1.Width(), m1.Height());
	for (size_t j = 0; j < result.Height(); j++)
	{
		for (size_t i = 0; i < result.Width(); i++)
		{
			result(i, j) = m1(i, j) - m2(i, j);
		}
	}

	return result;
}

// Matrix * Matrix = Matrix
inline Matrix& operator * (Matrix& m1, Matrix& m2)
{
	Matrix error = Matrix(1);
	if (m1.Width() != m2.Height()) // If first matrix'es columns count doesn't equal second matrix'es rows count - they can not be multiplied
		return error;

	Matrix result(m1.Height(), m2.Width());

	for (size_t j = 0; j < result.Height(); j++)
	{
		for (size_t i = 0; i < result.Width(); i++)
		{
			result(i, j) = 0;
			for (size_t k = 0; k < m1.Width(); k++)
			{
				result(i, j) += m1(i, k) * m2(k, j);
			}
		}
	}

	return result;
}

// Matrix == Matrix
inline bool operator == (Matrix& m1, Matrix& m2)
{
	if (m1.Height() != m2.Height() || m1.Width() != m2.Width()) // If matrixes are of different size - they are automatically not equal
		return false;

	for (size_t j = 0; j < m1.Height(); j++)
	{
		for (size_t i = 0; i < m1.Width(); i++)
		{
			if (m1(i, j) != m2(i, j)) // Comparing all the elements
				return false;
		}
	}

	return true;
}

// Matrix != Matrix
inline bool operator != (Matrix& m1, Matrix& m2)
{
	if (m1.Height() != m2.Height() || m1.Width() != m2.Width()) // If matrixes are of different size - they are automatically not equal
		return true;

	for (size_t j = 0; j < m1.Height(); j++)
	{
		for (size_t i = 0; i < m1.Width(); i++)
		{
			if (m1(i, j) != m2(i, j)) // Comparing all the elements
				return true;
		}
	}

	return false;
}

// For cout and other output streams
inline std::ostream& operator << (std::ostream& out, Matrix& m)
{
	for (size_t j = 0; j < m.Height(); j++)
	{
		for (size_t i = 0; i < m.Width(); i++)
		{
			out << m(i, j) << " ";
		}
		out << std::endl;
	}

	return out;
}