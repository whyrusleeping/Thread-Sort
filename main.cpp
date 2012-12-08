#include "ThrMergeSort.h"
#include "yardstick.h"
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

using std::cout;
int main(int argc, char *argv[])
{
	int count = 2000000;

	//Handle command line arguments.
	if(argc < 3)
	{
		cout << "Usage: './tmsort size depth'\n";
		return 1;
	}
	count = atoi(argv[1]);
	_ThreadSortRecurDepth = atoi(argv[2]);

	//Initialize two arrays
	vector<int> myar(count);
	srand(time(NULL));
	for(int i = 0; i < myar.size(); i++)
		myar[i] = rand(); 
	vector<int> myar2(myar);
	
	///Initialize timers
	//CPU time
	Yardstick y1;
	Yardstick y2;
	//Real Time
	struct timeval begin, mid, end;

	gettimeofday(&begin, NULL);
	y1.start();

	ThreadSort(&myar2); 

	struct timespec t1 = y1.end();
	gettimeofday(&mid, NULL);

	double threadsortTime = (double) (mid.tv_usec - begin.tv_usec)/1000000 + (double) (mid.tv_sec - begin.tv_sec);
	cout << "Threadsort:\t\nCPU time: " << (t1.tv_sec * 1000000000) + t1.tv_nsec << "\nReal Time: " << threadsortTime << "\n";
	//Check to ensure threadsort algorithm properly sorted the array.	
	for(int i = 1; i < myar2.size(); i++)
	{
		if(myar2[i-1] > myar2[i])
		{
			cout << "Incorrectly Sorted!!\n";
			break;
		}
	}

	gettimeofday(&mid, NULL);
	y2.start();

	mergeSort(&myar); //Mergesort for comparison

	struct timespec t2 = y2.end();
	gettimeofday(&end, NULL);

	double mergesortTime = (double) (end.tv_usec - mid.tv_usec)/1000000 + (double) (end.tv_sec - mid.tv_sec);
	cout << "Mergesort:\t\nCPU time: " << (t2.tv_sec * 1000000000) + t2.tv_nsec << "\nReal Time: " << mergesortTime << "\n";
	return 0;
}
