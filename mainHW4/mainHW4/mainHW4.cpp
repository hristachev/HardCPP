#include <iostream>
#include "insertsorted.h"
#include "signal.h"

int main()
{
    //TASK 1
    std::vector<double> vec;

    double array[]{ 1.1, 33.3, 7.2, 8.6, 15.7, 4.3 };
    unsigned arraySize = sizeof(array) / sizeof(double);
    std::sort(std::begin(array), std::end(array));

    std::copy(&array[0], &array[arraySize], std::back_inserter(vec));
    print(array);
    print(vec);
    insertSorted(vec, 15.1);
    print(array);
    print(vec);

    std::cout << std::endl << "_____________TASK 2_____________\n";
    //TASK 2
    const size_t sizeV = 100;
    std::vector<double_t> analogSignal(sizeV);
    std::vector<int64_t> digitalSignal(sizeV);

    vectorGenerate(analogSignal);
    std::copy(analogSignal.begin(), analogSignal.end(), digitalSignal.begin());

    printSignal(analogSignal, "Analog signal is: ");
    printSignal(digitalSignal, "Digital signal is: ");

    std::cout << "Error signal transformation is: " << calculateSignalError(analogSignal, digitalSignal) << std::endl;


    return 0;
}
