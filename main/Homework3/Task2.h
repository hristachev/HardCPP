#pragma once
#ifndef TASK2_H
#define TASK2_H
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix(int mSize) : size(mSize) { values.reserve(size * size); }
	int getSize();
	int& operator() (int fv, int sv);
	void print();
	void addValue(int value);
	~Matrix() {}

private:
	size_t size;
	std::vector<int*> values;
};

int Matrix::getSize() {
	return size;
}
int& Matrix::operator() (int fv, int sv){
	return *values[fv * size + sv];
}
void Matrix::print(){
	int temp = 0;
	for (auto value : values)
	{
		std::cout << *value << " | ";
		if (*value < 10) std::cout << " ";
		++temp;
		if (temp % size == 0) std::cout << std::endl;
	}
}
void Matrix::addValue(int value) {
	if (values.size() < size * size)
	{
		values.push_back(new int(value));
	}
}
int determinant(Matrix& matrixI){
	if (matrixI.getSize() == 2)
	{
		return (matrixI(0, 0) * matrixI(1, 1) - matrixI(0, 1) * matrixI(1, 0));
	}
	else
	{
		int determ = 0;
		for (int i = 0; i < matrixI.getSize(); ++i)
		{
			int temp = 1;
			if (i % 2 == 1)
			{
				temp = -1;
			}
			Matrix matrix(matrixI.getSize() - 1);
			for ( int j = 1; j < matrixI.getSize(); ++j)
			{
				for (int k = 0; k < matrixI.getSize(); ++k) {
					if (k != i)
					{
						matrix.addValue(matrixI(j, k));
					}
				}
			}
			determ += temp * (matrixI(0, i) * determinant(matrix));
		}
		return determ;
	}
}
#endif 