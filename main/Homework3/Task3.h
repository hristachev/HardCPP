#pragma once
#ifndef TASK3_H
#define TASK3_H

#include <iterator>

class Container
{
private:
	static const int size = 5;
	int data[size];
public:
	class Iterator {
	public:
		Iterator(int* iPtr) : ptr(iPtr) {}
		int& operator*() const { return *ptr; }
		int* operator->() { return ptr; }
		Iterator& operator++() {
			ptr++;
			return *this;
		}
		Iterator& operator++(int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}
		friend bool operator!=(const Iterator& fv, const Iterator& sv) { return (fv.ptr != sv.ptr); }
		friend bool operator==(const Iterator& fv, const Iterator& sv) { return (fv.ptr == sv.ptr); }
	private:
		int* ptr;
	};
	Iterator begin() { return Iterator(&data[0]); }
	Iterator end() { return Iterator(&data[size]); }
};
#endif