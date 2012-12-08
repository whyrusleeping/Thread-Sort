#ifndef THR_MERGE_SORT_H
#define THR_MERGE_SORT_H
#include <vector>
#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::vector;

//The maximum recursive depth (caps excess thread spawning)
/*class TSGlobals
{
	public:
		static int _ThreadSortRecurDepth;
};*/
//TSGlobals::_ThreadSortRecurDepth = 2;
extern int _ThreadSortRecurDepth;

//Main call for threadsort
void ThreadSort(vector<int> *arr);

//'Recursive' call for threadsort (i removed recursion on this due to performance issues)
void _ThreadSort(vector<int> *arr, int start, int end, int depth);

//Main call for mergesort (mostly just for comparison)
void mergeSort(vector<int> *arr);

//Recursive mergesort call
void _mergeSort(vector<int> *arr, int start, int end);

//Merge arr[start:mid] with arr[mid+1:end]
void merge(vector<int> *arr, int start, int mid, int end);

#endif
