#include "../includes.h"

//  ********************
//  *  PUBLIC METHODS  *
//  ********************

void Matrix::clear()
{
	for (size_t j = 0; j < _height; j++)
	{
		for (size_t i = 0; i < _width; i++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Matrix::recreateMatrix(size_t width, size_t height)
{
	this->_width = width;
	this->_height = height;

	deleteMatrix();
	allocateMemory();
	clear();
}

void Matrix::recreateMatrix(size_t size)
{
	recreateMatrix(size, size);
}

//  *********************
//  *  PRIVATE METHODS  *
//  *********************

void Matrix::allocateMemory()
{
	matrix = new double* [_width];
	for (size_t i = 0; i < _width; i++)
	{
		matrix[i] = new double[_height];
	}
}

void Matrix::deleteMatrix()
{
	for (size_t i = 0; i < _width; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

//  ****************
//  *  PROPERTIES  *
//  ****************

size_t& Matrix::Height()
{
	return _height;
}

size_t& Matrix::Width()
{
	return _width;
}