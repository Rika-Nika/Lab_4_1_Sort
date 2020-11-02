#pragma once
#include "Util.hpp"
#include <fcntl.h>
#include "framework.h"
#include <string>
#include <sstream>
#include <iostream>  


#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"

bool isValidTestAsc(Sequence<int>* seq)
{
	for (int i = 0; i < seq->GetLength() - 1; ++i)
	{
		if (seq->Get(i) > seq->Get(i + 1))
			return false;
	}
	return true;
}
bool isValidTestDsc(Sequence<int>* seq)
{
	for (int i = 0; i < seq->GetLength() - 1; ++i)
	{
		if (seq->Get(i) < seq->Get(i + 1))
			return false;
	}
	return true;
}

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
	do
	{
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
	while (i >= 0)
	{
		temp[k] = s[i];
		i--;
		k++;
	}
	temp[k] = '\0';
	return (temp);
}

ArraySequence<int>* getSeq(HWND hWnd, SizeSeq sizeSeq, bool gen, const char* path)
{
	ArraySequence<int>* res;
	int size = static_cast<int>(sizeSeq);
	int* testArr;
	std::string out;
	std::ostringstream oss;;
	if (gen)
	{
		testArr = getRandomNumbers(0, size);
		res = new ArraySequence<int>(testArr, size);

		for (int i = 0; i < size; i++)
		{
			oss << testArr[i] << "\r\n";
		}
	}
	else
	{
		res = getFromFile(path);
		for (int i = 0; i < res->GetLength(); i++)
		{
			oss << res->Get(i) << "\r\n";
		}
	}
	out = oss.str();
	std::wstring stemp = s2ws(out);
	LPCWSTR result = stemp.c_str();
	SetWindowText(hWnd, result);
	return res;
}
int integerCompare(int a, int b) {
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return 0;
	}
	else {
		return 2;
	}
}

int integerCompareDsc(int a, int b) {
	if (a < b) {
		return 1;
	}
	else if (a > b) {
		return 0;
	}
	else {
		return 2;
	}
}

std::ostringstream testSeq(Sequence<int>* seq1, ISorter<int>* shellSorter1)
{
	Sequence<int>* res1Seq1 = shellSorter1->sort(seq1, integerCompare);
	std::ostringstream oss;
	oss << "Сортировка произвольной последовательности." << "\r\n";
	oss << "Время сортировки (мс): " << shellSorter1->getTimeOfIterationSeconds() << "\r\n";
	oss << "Шагов сортировки: " << shellSorter1->getCountOfIter() << "\r\n";
	if (isValidTestAsc(res1Seq1))
	{
		oss << "Тест пройден." << "\r\n";
	}
	else
	{
		oss << "Тест завален." << "\r\n";
	}
	oss << "---Log теста 1---" << "\r\n";
	oss << res1Seq1->PrintOut();
	Sequence<int>* res2Seq1 = shellSorter1->sort(res1Seq1, integerCompare);
	oss << "Сортировка сортированной последовательности." << "\r\n";
	oss << "Время сортировки (мс): " << shellSorter1->getTimeOfIterationSeconds() << "\r\n";
	oss << "Шагов сортировки: " << shellSorter1->getCountOfIter() << "\r\n";
	if (isValidTestAsc(res2Seq1))
	{
		oss << "Тест пройден." << "\r\n";
	}
	else
	{
		oss << "Тест завален." << "\r\n";
	}
	oss << "---Log теста 2---" << "\r\n";
	oss << res2Seq1->PrintOut();
	Sequence<int>* res3Seq1 = shellSorter1->sort(res2Seq1, integerCompareDsc);
	oss << "Обратная сортировка сортированной последовательности." << "\r\n";
	oss << "Время сортировки (мс): " << shellSorter1->getTimeOfIterationSeconds() << "\r\n";
	oss << "Шагов сортировки: " << shellSorter1->getCountOfIter() << "\r\n";
	if (isValidTestDsc(res3Seq1))
	{
		oss << "Тест пройден." << "\r\n";
	}
	else
	{
		oss << "Тест завален." << "\r\n";
	}
	oss << "---Log теста 3---" << "\r\n";
	oss << res3Seq1->PrintOut();
	return oss;
}

void startTest(HWND hWndInput, HWND hWndOutput1, HWND hWndOutput2, Alg alg1, Alg alg2,
               TypeImpl type_impl1, TypeImpl type_impl2, ArraySequence<int>* inputSeq)
{
	Sequence<int>* seq1;
	Sequence<int>* seq2;
	switch (type_impl1)
	{
	case TypeImpl::ARRAY_LIST:
		seq1 = new ArraySequence<int>(*inputSeq);
		break;
	case TypeImpl::LINKED_LIST:
		seq1 = new LinkedListSequence<int>(*inputSeq);
		break;
	default:
		seq1 = new ArraySequence<int>(*inputSeq);
		break;
	}
	switch (type_impl2)
	{
	case TypeImpl::ARRAY_LIST:
		seq2 = new ArraySequence<int>(*inputSeq);
		break;
	case TypeImpl::LINKED_LIST:
		seq2 = new LinkedListSequence<int>(*inputSeq);
		break;
	default:
		seq2 = new ArraySequence<int>(*inputSeq);
		break;
	}
	ISorter<int>* sorter1;
	ISorter<int>* sorter2;
	switch (alg1)
	{
	case Alg::HEAP:
		sorter1 = new HeapSorter<int>();
		break;
	case Alg::SHELL:
		sorter1 = new ShellSorter<int>();
		break;
	case Alg::BUBBLE:
	case Alg::PYRAMID:
	case Alg::QUICK:
	default:
		sorter1 = new ShellSorter<int>();
		break;
	}
	switch (alg2)
	{
	case Alg::HEAP:
		sorter2 = new HeapSorter<int>();
		break;
	case Alg::SHELL:
		sorter2 = new ShellSorter<int>();
		break;
	case Alg::BUBBLE:
	case Alg::PYRAMID:
	case Alg::QUICK:
	default:
		sorter2 = new ShellSorter<int>();
		break;
	}
	std::ostringstream oss;
	oss =testSeq(seq1, sorter1);
	std::string out = oss.str();
	std::wstring stemp = s2ws(out);
	LPCWSTR result = stemp.c_str();
	SetWindowText(hWndOutput1, result);

	oss = testSeq(seq2, sorter2);
	out = oss.str();
	stemp = s2ws(out);
	result = stemp.c_str();
	SetWindowText(hWndOutput2, result);
}

