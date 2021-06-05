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
	double& Element(int x, int y);
	size_t& Height();
	size_t& Width();

	// CONSTRUCTORS AND DESTRUCTOR
	Matrix(size_t height, size_t width) : _width(width), _height(height)
	{
		allocateMemory();
		clear();
	}

	Matrix(int size) : Matrix(size, size) { };

private:
	double** matrix;
	size_t _height{ 0 }, _width{ 0 };

	// PRIVATE METHODS
	void allocateMemory();
	void deleteMatrix();

};