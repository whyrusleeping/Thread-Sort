#ifndef THR_MERGE_SORT_H
#define THR_MERGE_SORT_H
#include <vector>
#include <iostream>
#include <thread>

using std::thread;
using std::cout;
using std::vector;

void ThreadSort(vector<int> *arr);
void _ThreadSort(vector<int> *arr, int start, int end, int depth);
void _mergeSort(vector<int> *arr, int start, int end);
void mergeSort(vector<int> *arr);
void merge(vector<int> *arr, int start, int mid, int end);

#endif
