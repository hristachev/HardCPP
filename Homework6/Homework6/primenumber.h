#pragma once
#ifndef PRIMENUMBER_H
#define PRIMENUMBER_H
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

bool isPrime(int number) {
	for (int j = 2; j * j <= number; ++j) {
		if (number % j == 0) {
			if (number == 2) break;
			return false;
		}
	}
	return true;
}

std::mutex mut;


void primeNumber(int val) {
	std::vector<int> primes;
	for (int i = 0; i < val; ++i)
	{
		if (isPrime(i)) {
			std::lock_guard lg(mut);
			primes.push_back(i);
		
		}
	}
	std::cout << primes.size() << "th primary number is: " << primes.back() << std::endl;
}

//void primeNumberBar(int val) {
//	bool isPrime = true;
//	std::vector<int> simple;
//	std::vector<int> other;
//	for (int i = 2; i < val; ++i) {
//		for (int j = 2; j <= (sqrt(abs(i))); j++)
//		{
//			if (i % j == 0) {
//				if (i == 2) break;
//				isPrime = false;
//				break;
//			}
//			else {
//				isPrime = true;
//				continue;
//			}
//		}
//		if (isPrime) {
//			simple.push_back(i);
//		}
//	}
//	std::cout << simple.size() << "th primary number is: " << simple.back() << std::endl;
//}


void progress() {
	std::lock_guard lg(mut);
	double progress = 0.0;
	while (progress < 1.0) {
		int barWidth = 50;
		std::cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos) std::cout << "=";
			else if (i == pos) std::cout << ">";
			else std::cout << " ";
			//std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << "] " << (int(progress * 100.0) + 1) << " %\r";
		std::cout.flush();
		progress += 0.01;
	}
	std::cout << std::endl;
}

#endif // !PRIMENUMBER_H