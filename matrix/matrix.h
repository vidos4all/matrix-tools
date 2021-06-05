#pragma once
#include "../includes.h"

class Matrix
{
public:
	// PUBLIC METHODS
	void clear();
	void recreateMatrix(size_t width, size_t height);
	void recreateMatrix(size_t size);

	// PROPERTIES
	size_t& Height();
	size_t& Width();

	// CONSTRUCTORS AND DESTRUCTOR
	Matrix(size_t height, size_t width) : _width(width), _height(height)
	{
		allocateMemory();
		clear();
	}

	Matrix(int size) : Matrix(size, size) { };

	// IN-CLASS OPERATOR OVERRIDES
	double& operator () (const int& x, const int& y)
	{
		return matrix[x][y];
	}

	Matrix& operator = (Matrix& m)
	{
		if (this == &m)
			return *this;

		recreateMatrix(m.Width(), m.Height());
		for (size_t j = 0; j < m.Height(); j++)
		{
			for (size_t i = 0; i < m.Width(); i++)
			{
				matrix[i][j] = m(i, j);
			}
		}

		return *this;
	}

private:
	double** matrix;
	size_t _height{ 0 }, _width{ 0 };

	// PRIVATE METHODS
	void allocateMemory();
	void deleteMatrix();

};