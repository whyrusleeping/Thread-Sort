#ifndef __THREADSORT_H_
#define __THREADSORT_H_

#include <vector>
#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::vector;

template <class T>
void merge(vector<T> *arr, int start, int mid, int end)
{
	vector<T> sorted((end - start) + 1);
	int sortPos = 0;
	int leftPos = start;
	int rightPos = mid+1;

	while(sortPos < sorted.size())
	{
		if(!(leftPos > mid || rightPos > end))
		{			
			if((*arr)[leftPos] < (*arr)[rightPos])
				sorted[sortPos++] = (*arr)[leftPos++];
			else
				sorted[sortPos++] = (*arr)[rightPos++];
		}
		else
		{
			if(!leftPos > mid)
				sorted[sortPos++] = (*arr)[leftPos++];
			else if(!rightPos > end)
				sorted[sortPos++] = (*arr)[rightPos++];
			else
				break;
		}
	}

	for(int i = 0; i < sorted.size(); i++)
	{
		(*arr)[start + i] = sorted[i];
	}
}

template <class T>
void _mergeSort(vector<T> *arr, int start, int end)
{
	//cout << "mergesort: " << start << " to " << end << "\n";
	int mid = (end + start) / 2;
	//for(int i = start; i < end; i++)
	//	cout << (*arr)[i] << " ";
	//cout << "\n";
	//cout << "mid: " << mid << "\n\n";
	if(start < end)
	{
		_mergeSort<T>(arr, start, mid);
		_mergeSort<T>(arr, mid + 1, end);
		merge<T>(arr, start, mid, end);
	}
}

template <class T>
void mergeSort(vector<T> *arr)
{
	_mergeSort<T>(arr,0,(*arr).size()-1);
}

template <class T>
void _ThreadSort(vector<T> *arr, int start, int end, int depth)
{
	int mid = (end - start) / 2;
	if(depth < 2)
	{
		thread tl(_ThreadSort<T>, arr, start, mid, depth +1);
		thread tr(_ThreadSort<T>, arr, mid+1, end, depth +1);
		tl.join();
		tr.join();
		merge<T>(arr, start, mid, end);
	}
	else
	{
		_mergeSort<T>(arr, start, end);
	}
}

template <class T>
void ThreadSort(vector<T> *arr)
{
	_ThreadSort<T>(arr, 0, (*arr).size()-1,0); 
}




#endif
