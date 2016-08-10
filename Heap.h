#pragma once
#include<stdio.h>
#include <vector>
#include<assert.h>
#include<iostream>
using namespace std;
template<class T>
struct Less           // 小堆

{
	bool operator() (const T& l, const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater     //大堆
{
	bool operator() (const T& l, const T& r)
	{
		return l > r; 
	}
};

template<class T, class Compare = Less<T>>
class Heap
{
public:
	Heap()
	{}

	Heap(const T* a, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			_arrays.push_back(a[i]);
		}

		for (int i = (_arrays.size() - 2) / 2; i >= 0; --i)  // 建堆
		{
			AdjustDown(i);
		}
	}

	void Push(const T& x)
	{
		_arrays.push_back(x);
		AdjustUp(_arrays.size() - 1);
	}

	void Pop()
	{
		assert(_arrays.size());
		swap(_arrays[0], _arrays[_arrays.size() - 1]);
		_arrays.pop_back();

		AdjustDown(0);
	}

	T& Top()
	{
		assert(_arrays.size() > 0);
		return _arrays[0];
	}

	bool Empty()
	{
		return _arrays.empty();
	}

	int Size()
	{
		return _arrays.size();
	}

	

	

	void Print()
	{
		for (size_t i = 0; i < _arrays.size(); ++i)
		{
			cout << _arrays[i] << " ";
		}
		cout << endl;
	}

private:
	vector<T> _arrays;
	void AdjustDown(int root)        //找到第一个非叶子结点，也就是从这里开始调
	{
		int child = root * 2 + 1;
		Compare com;
		while (child < _arrays.size())
		{
			// 比较出左右孩子中小的那个
			if (child + 1<_arrays.size() &&
				com(_arrays[child + 1], _arrays[child]))
			{
				++child;
			}
			if (com(_arrays[child], _arrays[root]))
			{
				swap(_arrays[child], _arrays[root]);
				root = child;
				child = 2 * root + 1;
			}
			else
			{
				break;
			}
		}
	}
	void HeapSort(int* a, size_t size)
	{
		// 建堆
		for (int i = (size - 2) / 2; i >= 0; --i)
		{
			AdjustDown(a, size, i);
		}

		// 选数据排序
		for (size_t i = 0; i < size; ++i)
		{
			swap(a[0], a[size - i - 1]);
			AdjustDown(a, size - i - 1, 0);
		}
	}
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;

		//while (parent >= 0)
		while (child > 0)
		{
			if (Compare()(_arrays[child], _arrays[parent]))
			{
				swap(_arrays[parent], _arrays[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
};

template<class T>
class PriorityQueue
{
public:
	void Push(const T& x)
	{
		_hp.Push(x);
	}

	void Pop()
	{
		_hp.Pop();
	}

public:
	Heap<T> _hp;
};

//void Test1()
//{
//	int a[10] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
//	Heap<int, Greater<int> > hp1(a, 10);
//	//hp1.Push(1);
//	hp1.Print();
//
//	Heap<int> hp2(a, 10);
//	//hp2.Push(1);
//	hp2.Print();
//
//
	//Less<int> less;
	//cout<<less(1, 2)<<endl;

	//Greater<int> greater;
	//cout<<greater(1, 2)<<endl;
//}

//#include <list>

//void Test2()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	vector<int>::iterator it = v1.begin();
//	while (it != v1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//
//	list<int>::iterator listIt = l1.begin();
//	while (listIt != l1.end())
//	{
//		cout << *listIt << " ";
//		++listIt;
//	}
//
//	cout << endl;
//}

//
//void TestHeapSort()
//{
//	int a[10] = { 5, 9, 2, 3, 0, 1, 7, 8, 4, 6 };
//	HeapSort(a, 10);
//}