#pragma once
#include <random>
#include "Sorter.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

enum class SizeSeq {
    SMALL = 10,
    MEDIUM = 1000,
    LARGE = 10000
};

enum class Alg {
    BUBBLE,
    SHELL,
    PYRAMID,
    QUICK,
    HEAP
};

bool chckValue(const int* arr, int size, int x) {
    bool res = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            res = true;
        }
    }
    return res;
}
int* getRandomNumbers(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    auto* values = new int[max - min];
    int value;
    int size = 0;
    for (int i = min; i < max; ++i) {
        value = static_cast<int>(rand() * fraction * (max - min + 1) + min);
        if (!chckValue(values, size, value)) {
            values[i] = value;
            size++;
        }
        else {
            i--;
        }
    }
    return values;
}

std::string getFromFile(const char * path) {

    int* values = nullptr;
    const char* pathPref = "c:\\tmp\\";
    std::stringstream ss;

    ss << pathPref << path;
    std::ifstream file(ss.str(), std::ios_base::in);
    std::stringstream res;
    int a;
    while (file >> a)
    {
       res<<a<<"\r\n";
    }
    return res.str();
}
