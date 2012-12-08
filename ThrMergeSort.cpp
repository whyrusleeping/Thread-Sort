#include "ThrMergeSort.h"


void ThreadSort(vector<int> *arr)
{
	_ThreadSort(arr, 0, (*arr).size()-1); 
}

void _ThreadSort(vector<int> *arr, int start, int end)
{
		int mid = (end - start) / 2;
		int midl = mid / 2;
		int midr = (mid / 2) + mid;
		thread tl(_mergeSort, arr, start, midl);
		thread tlm (_mergeSort, arr, midl + 1, mid);
		thread trm (_mergeSort, arr, mid + 1, midr);
		thread tr(_mergeSort, arr, midr + 1, end);
		tl.join();
		tr.join();
		tlm.join();
		trm.join();
		thread mergeTl(merge, arr, start, midl, mid);
		thread mergeTr(merge, arr, mid + 1, midr, end);
		mergeTl.join();
		mergeTr.join();
		merge(arr, start, mid, end);
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

