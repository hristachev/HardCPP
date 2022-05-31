#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"

int main()
{
    //TASK 1
    list<double> dd = { 1.1, 2.2, 3.3, 4.4, 5.5 ,6.6 };
    printlst(dd);
    func1(dd);
    printlst(dd);
    //TASK 2
    Matrix matrix(2);
    matrix.addValue(5);
    matrix.addValue(54);
    matrix.addValue(11);
    matrix.addValue(12);
    matrix.print();
    std::cout << "Determinant is: " << determinant(matrix) << std::endl;
    //TASK 3
    Container example;
    for (auto temp : example) {
        temp = 0;
        std::cout << temp << " ";
    }


    return 0;
}
