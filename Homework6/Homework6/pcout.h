#pragma once
#ifndef PCOUT_H
#define PCOUT_H

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

class pcout{
public:
	pcout() : uM(std::unique_lock<std::mutex>(m)) {}
	
	template<typename T>
	pcout& operator<< (const T& inp) {
		std::cout << inp;
		return *this;
	}
	pcout& operator<< (std::ostream& (*it)(std::ostream&)) {
		std::cout << it;
		return *this;
	}

private:
	std::unique_lock<std::mutex> uM;
};

void doSomething(int number) {
	pcout() << "start thread " << number << std::endl; 
	pcout() << "stop thread " << number << std::endl;
}
#endif // !PCOUT_H