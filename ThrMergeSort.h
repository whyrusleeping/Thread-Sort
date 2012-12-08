#ifndef THR_MERGE_SORT_H
#define THR_MERGE_SORT_H
#include <vector>
#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::vector;

//Main call for threadsort
void ThreadSort(vector<int> *arr);

//'Recursive' call for threadsort (i removed recursion on this due to performance issues)
void _ThreadSort(vector<int> *arr, int start, int end);

//Main call for mergesort (mostly just for comparison)
void mergeSort(vector<int> *arr);

//Recursive mergesort call
void _mergeSort(vector<int> *arr, int start, int end);

//Merge arr[start:mid] with arr[mid+1:end]
void merge(vector<int> *arr, int start, int mid, int end);

#endif
