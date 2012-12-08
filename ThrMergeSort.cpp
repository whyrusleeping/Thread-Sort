#include "ThrMergeSort.h"


void ThreadSort(vector<int> *arr)
{
	//Call _Threadsort with appropriate parameters.
	_ThreadSort(arr, 0, (*arr).size()-1); 
}

void _ThreadSort(vector<int> *arr, int start, int end)
{
		//Find middle of array
		int mid = (end - start) / 2;

		//Break array into four segments by finding secondary midpoints
		int midl = mid / 2;
		int midr = (mid / 2) + mid;

		//Create thread to mergesort each of those four segments
		thread tl(_mergeSort, arr, start, midl);
		thread tlm (_mergeSort, arr, midl + 1, mid);
		thread trm (_mergeSort, arr, mid + 1, midr);
		thread tr(_mergeSort, arr, midr + 1, end);

		//Wait for each thread to finish
		tl.join();
		tr.join();
		tlm.join();
		trm.join();

		//merge left halves and right halves asynchronously
		thread mergeTl(merge, arr, start, midl, mid);
		thread mergeTr(merge, arr, mid + 1, midr, end);
		mergeTl.join();
		mergeTr.join();

		//finally merge left with right
		merge(arr, start, mid, end);
}

void mergeSort(vector<int> *arr)
{
	_mergeSort(arr,0,(*arr).size()-1);
}

//Standard mergesort algorithm, sort left, sort right, merge.
void _mergeSort(vector<int> *arr, int start, int end)
{
	if(start < end)
	{
		int mid = (end + start) / 2;
		_mergeSort(arr, start, mid);
		_mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

//Merge two vectors into one in sorted order
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

