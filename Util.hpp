#pragma once
#include <random>
#include "Sorter.hpp"
#include <fstream>
#include <iostream>
#include <sstream>


#include "ArraySequence.hpp"
#include "DynamicArray.hpp"

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

enum class TypeImpl {
    ARRAY_LIST,
	LINKED_LIST
};

//int integerCompare(int a, int b) {
//    if (a > b) {
//        return 1;
//    }
//    else if (a < b) {
//        return 0;
//    }
//    else {
//        return 2;
//    }
//}



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
    static const auto fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    auto* values = new int[max - min];
    auto size = 0;
    for (auto i = min; i < max; ++i) {
	    const auto value = static_cast<int>(rand() * fraction * (max - min + 1) + min);
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

ArraySequence<int> * getFromFile(const char * path) {
	
	ArraySequence<int> * res = new ArraySequence<int>();
	
    int* values = nullptr;
    const char* pathPref = "c:\\tmp\\";
    std::stringstream ss;
    ss << pathPref << path;
    std::ifstream file(ss.str(), std::ios_base::in);

    int a;
    while (file >> a)
    {
       res->Append(a);
    }
    return res;
}
