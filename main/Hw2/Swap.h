#pragma once
#ifndef SWAP_H
#define SWAP_H
#include <iostream>

template<typename T1>
void swap(T1* ptr1, T1* ptr2) {
	T1 temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
template<typename T>
void info(T* ptr1, T* ptr2, T a, T d) {
	std::cout << "*ptr1 = " << *ptr1 << "|" << "*ptr2 = " << *ptr2 << std::endl;
	std::cout << "ptr1 = " << ptr1 << "|" << "ptr2 = " << ptr2 << std::endl;
	std::cout << "val1 = [" << a << "] " << &a << "|" << "val2 = [" << d << "] " << &d << std::endl;
}
#endif
