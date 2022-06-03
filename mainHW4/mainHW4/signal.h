#pragma once
#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <algorithm>
#include <math.h>
#include <numeric>


void vectorGenerate(std::vector<double>& vect) {
	std::generate(vect.begin(), vect.end(), [n = 0]() mutable {
		return std::sin(n++ *(2*M_PI/100))*5;
	});
}

double_t calculateSignalError(std::vector<double_t>& fVec, std::vector<int64_t>& sVec) {
	return std::inner_product(fVec.begin(), fVec.end(), sVec.begin(), 0.0,
		std::plus<double_t>{},
		[](double_t f, int64_t s)
		{
			return std::pow(f - s, 2);
		});
}

template<typename T>
void printSignal(T& val, const std::string name) {
	std::cout << name;
	for (auto out : val)
	{
		std::cout << out << " ";
	}
	std::cout << std::endl;
}

#endif