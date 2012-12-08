#include "ThrMergeSort.h"

void ThreadSort(vector<int> *arr)
{
	_ThreadSort(arr, 0, (*arr).size()-1,0); 
}

void _ThreadSort(vector<int> *arr, int start, int end, int depth)
{
	int mid = (end - start) / 2;
	if(depth < 2)
	{
		thread tl(_ThreadSort, arr, start, mid, depth +1);
		thread tr(_ThreadSort, arr, mid+1, end, depth +1);
		tl.join();
		tr.join();
		merge(arr, start, mid, end);
	}
	else
	{
		_mergeSort(arr, start, end);
	}
}

void mergeSort(vector<int> *arr)
{
	_mergeSort(arr,0,(*arr).size()-1);
}

void _mergeSort(vector<int> *arr, int start, int end)
{
	//cout << "mergesort: " << start << " to " << end << "\n";
	int mid = (end + start) / 2;
	//for(int i = start; i < end; i++)
	//	cout << (*arr)[i] << " ";
	//cout << "\n";
	//cout << "mid: " << mid << "\n\n";
	if(start < end)
	{
		_mergeSort(arr, start, mid);
		_mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void merge(vector<int> *arr, int start, int mid, int end)
{
	vector<int> sorted((end - start) + 1);
	int sortPos = 0;
	int leftPos = start;
	int rightPos = mid+1;

	while(sortPos < sorted.size())
	{
		if(leftPos <= mid && rightPos <= end)
		{			
			if((*arr)[leftPos] < (*arr)[rightPos])
				sorted[sortPos++] = (*arr)[leftPos++];
			else
				sorted[sortPos++] = (*arr)[rightPos++];
		}
		else
		{
			if(leftPos <= mid)
				sorted[sortPos++] = (*arr)[leftPos++];
			else if(rightPos <= end)
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

