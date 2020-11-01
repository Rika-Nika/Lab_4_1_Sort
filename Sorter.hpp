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
class ShellSorter : public ISorter<T>
{

public:
	ShellSorter();

	~ShellSorter();
	
	Sequence<T>* sort(Sequence<T>*, int (*cmp)(T, T)) override;
};
template<typename T>
ShellSorter<T>::ShellSorter() = default;

template<typename T>
ShellSorter<T>::~ShellSorter() = default;

template<typename T>
Sequence<T>* ShellSorter<T>::sort(Sequence<T> * input, int (*cmp)(T, T)) {
	//
	return nullptr;
}


