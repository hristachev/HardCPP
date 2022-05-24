#include <iostream>
#include "SortPointers.h"
#include "Swap.h"
#include "WarAndPeace.h"

int main() {
	std::setlocale(LC_ALL, "Ru");
	//TASK 1
	int a{ 12 };
	int* ptrI = &a;
	int d{ 4 };
	int* ptrD = &d;
	info(ptrI, ptrD, a, d);
	swap(&ptrI, &ptrD);
	std::cout << "-------------------after swap-------------------\n";
	info(ptrI, ptrD, a, d);
	
	//TASK 2
	std::cout << "\n\t----------TASK 2: ----------\n";
	int b{ 5 }, c{1}, *ptrA{&b}, *ptrB{&c};
	std::cout << "\n";
	std::vector<int*> ptrVector{ ptrI, ptrD, ptrA, ptrB};
	printVec(ptrVector);
	SortPointers(ptrVector);
	printVec(ptrVector);

	//TASK 3
	std::cout << "\n\t----------TASK 3: ----------\n";
	countVowelsCIFFND();
	countVowelsCIFFOR();
	countVowelsFORFND();
	countVowelsFORX2();


	return 0;
}