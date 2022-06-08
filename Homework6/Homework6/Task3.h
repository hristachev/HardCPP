#pragma once
#ifndef TASK_THIRD_H
#define TASK_THIRD_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <random>

std::mutex mtx;

void generateVal(std::vector<int>& vec)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1000);

    std::lock_guard lg(mtx);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::generate(vec.begin(), vec.end(), [&]()
        {
            return dis(gen);
        });
    std::vector<int>::iterator it = std::prev(vec.end());
    std::cout << *it << " is put" << std::endl;
}

void thing(std::vector<int>& vec)
{
    std::lock_guard lg(mtx);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << *std::max_element(vec.begin(), vec.end()) << " is steal" << std::endl;
}
#endif // !TASK_THIRD_H