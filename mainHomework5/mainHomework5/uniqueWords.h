#pragma once
#ifndef UNIQUEWORDS_H
#define UNIQUEWORDS_H
#include <vector>
#include <iostream>
#include <set>

template<typename T, typename it>
void uniqueWords(const it& itBegin, const it& itEnd) {
	/*for(T it1 = itBegin; p1 != itEnd; ++it1)
	{
		for (T it2 = itBegin; it2 != it1; ++it2)
			if (*it1 == *it2)
				break;
		if (it1 == it2)
			std::cout << *it1 << " ";
	}
	std::cout << std::endl*/
	std::set<T> itSet;
	std::copy(itBegin, itEnd, std::inserter(itSet, itSet.end()));
	std::copy(itSet.begin(), itSet.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

template<typename T>
void print(T& val) {
	for (auto out : val)
	{
		std::cout << out << " ";
	}
	std::cout << std::endl;
}



#endif // !UNIQUEWORDS_H