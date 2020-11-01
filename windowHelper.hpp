#pragma once
#include "Util.hpp"
#include <fcntl.h>
#include "framework.h"
#include <string> 
#include <sstream>
#include <iostream>     // std::cout, std::noskipws

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

// Функция преобразования числа в строку
char* IntToStr(int n)
{
    char s[40], t, * temp;
    int i, k;
    int sign = 0;
    i = 0;
    k = n;
    if (k < 0)
    {
        sign = 1;
        k = -k;
    }
    do {
        t = k % 10;
        k = k / 10;
        s[i] = t | 0x30;
        i++;
    } while (k > 0);
    if (sign == 1)
    {
        s[i] = '-';
        i++;
    }
    temp = new char[i];
    k = 0;
    i--;
    while (i >= 0) {
        temp[k] = s[i];
        i--; k++;
    }
    temp[k] = '\0';
    return(temp);
}
void getSeq(HWND hWnd, SizeSeq sizeSeq, bool gen, const char* path) {
    int size = static_cast<int>(sizeSeq);
    int* testArr;
    std::string out;
    if (gen) {
        testArr = getRandomNumbers(0, size);
        std::ostringstream oss;
        for (int i = 0; i < size; i++) {
            oss << testArr[i] << "\r\n";
        }
        out = oss.str();
    }
    else {
        out = getFromFile(path);
    }
    std::wstring stemp = s2ws(out);
    LPCWSTR result = stemp.c_str();

	SetWindowText(hWnd, result);
}
void startTest(HWND hWnd1, HWND hWnd2) {
    int testArr[5] = { 11, 112, 23, 153, 122222 };
    std::ostringstream oss;

    oss << testArr;
    auto out = oss.str();
    std::wstring stemp = s2ws(out);
    LPCWSTR result = stemp.c_str();

    SetWindowText(hWnd1, result);
    SetWindowText(hWnd2, result);
}
