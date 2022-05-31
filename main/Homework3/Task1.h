#pragma once
#ifndef TASK1_H
#define TASK1_H
#include <iostream>
#include <list>

using namespace std;

void func1(list<double>& elem) {
	double d{0};
	int val{0};
	list<double>::const_iterator it = elem.begin();
	while (it != elem.end()) {
		d = d + *it;
		++val;
		++it;
	}
	if (val != 0)
		elem.push_back(d / elem.size());
}
void printlst(const list<double>& elem) {
	for (auto it = elem.begin(); it != elem.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
#endif 