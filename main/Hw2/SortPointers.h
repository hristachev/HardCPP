#pragma once
#ifndef SORTPOINTERS_H
#define SORTPOINTERS_H
#include <vector>
#include <algorithm>

template<typename T>
void SortPointers(std::vector<T*> &vec) {
	std::sort(vec.begin(), vec.end(), [](const T* lv, const T* rv) { return *lv < *rv; });
}

template<typename T>
void printVec(const std::vector<T*>& vec) {
	auto iterator = vec.begin();
	while (iterator != vec.end())
	{
		std::cout << **iterator << " ";
		++iterator;
	}
	std::cout << "\n";
}

#endif