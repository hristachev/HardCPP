#pragma once
#ifndef INSERTSORTED_H
#define INSERTSORTED_H

#include <iostream>
#include <vector>

template<typename T>
void insertSorted(std::vector<T>& vec, T val) {
	auto it = vec.begin();
	int temp{0};
	while (true)
	{
		std::cout << "Enter the position number to insert: ";
		std::cin >> temp;
		if (temp > vec.size())
			std::cerr << "Error! Vector has less size!!!\n";
		else {
			vec.insert((it + temp) - 1, val);
			break;
		}
	}
}

template<typename T>
void print(T& val) {
	for (auto out : val)
	{
		std::cout << out << " ";
	}
	std::cout << std::endl;
}

#endif 
