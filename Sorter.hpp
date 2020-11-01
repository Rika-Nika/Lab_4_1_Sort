#pragma once
#include "Sequence.hpp"


template  <typename T>
class ISorter
{
	//public:
	//	virtual Sequence
	//
	//	<T>* sortQuick(Sequence<T>* seq, int (*cmp)(T, T)) = 0;
	//	virtual Sequence<T>* sortPyramid(Sequence<T>* seq, int (*cmp)(T, T)) = 0;
	//	virtual Sequence<T>* ShellSort(Sequence<T>* seq, int (*cmp)(T, T)) = 0;
	//	virtual int comp(int a, int b) = 0;
	//	virtual int comp(double a, double b) = 0;
	//
	//	virtual ~ISorter() {};

protected:
	int (*cmp)(T, T);
public:
	ISorter(int(*cmp)(T, T))
	{
		this->cmp = cmp;
	}
public:
	virtual Sequence<T>* Sort(Sequence<T>* input) = 0;
protected:
	void Swap(Sequence<T>* seq, int index1, int index2)
	{
		T item = seq->Get(index1);
		seq->Get(index1) = seq->Get(index2);
		seq->Get(index2) = item;
	}
public:


};

template <typename T>
class BubbleSorter : public ISorter<T>
{
public:

public:
	BubbleSorter();

	~BubbleSorter();

	Sequence<T>* sort(Sequence<T>*, int (*cmp)(T, T)) override;
};
template<typename T>
BubbleSorter<T>::BubbleSorter() = default;

template<typename T>
BubbleSorter<T>::~BubbleSorter() = default;

template<typename T>
Sequence<T>* BubbleSorter<T>::sort(Sequence<T> * input, int (*cmp)(T, T)) {
	//
	return nullptr;
}


template <typename T>
class BubbleSorter2 :public ISorter<T>
{
public:
	virtual Sequence<T>* Sort(Sequence<T>* input) override
	{
		//
		return nullptr;
	}
};
template <typename T>
class BubbleSorter3 :public ISorter<T>
{
public:
	virtual Sequence<T>* Sort(Sequence<T>* input) override
	{
		//
		return nullptr;
	}
};

