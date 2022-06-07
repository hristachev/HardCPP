#include <iostream>
#include <list>
#include "uniqueWords.h"
#include "counterWords.h"

int main()
{
    //TASK 1
    std::vector<std::string> str{ "the", "hi", "good", "a", "what", "hi", "hi", "good"};
    std::cout << "Vector is: ";
    print(str);
    std::cout << "Unique words: ";
    uniqueWords<std::string>(str.begin(), str.end());

    std::list<std::string> lst{ "the", "hi", "good", "a", "what", "hi", "hi", "ok", "a"};
    std::cout << "List is: ";
    print(lst);
    std::cout << "Unique words: ";
    uniqueWords<std::string>(lst.begin(), lst.end());

    //TASK 2
    std::cout << std::endl << "Enter text: ";
    std::string example;

    std::cin.unsetf(std::ios::skipws);
    std::getline(std::cin, example);
   
    for (const auto& [counter, sentence] : getText(example)) {
        std::cout << '[' << counter << "] words: " << sentence << std::endl;
    }
   
    


    return 0;
}
