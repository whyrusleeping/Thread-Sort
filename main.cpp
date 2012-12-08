#include "ThrMergeSort.h"
#include "yardstick.h"
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

using std::cout;
int main(int argc, char *argv[])
{
	//Initialize two arrays
	int count = 2000000;
	if(argc > 1)
		count = atoi(argv[1]);
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
	y2.start();
	mergeSort(&myar);
	struct timespec t2 = y2.end();
	gettimeofday(&end, NULL);

	double threadsortTime = (double) (mid.tv_usec - begin.tv_usec)/1000000 + (double) (mid.tv_sec - begin.tv_sec);
	double mergesortTime = (double) (end.tv_usec - mid.tv_usec)/1000000 + (double) (end.tv_sec - mid.tv_sec);

	cout << "Threadsort:\t\nCPU time: " << (t1.tv_sec * 1000000000) + t1.tv_nsec << "\nReal Time: " << threadsortTime << "\n";
	
	cout << "Mergesort:\t\nCPU time: " << (t2.tv_sec * 1000000000) + t2.tv_nsec << "\nReal Time: " << mergesortTime << "\n";
	return 0;
}
