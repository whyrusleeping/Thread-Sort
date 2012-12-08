#include "ThrMergeSort.h"
#include "yardstick.h"
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
	
	//Initialize timers
	Yardstick y1;
	Yardstick y2;

	y1.start();
	ThreadSort(&myar2);
	struct timespec t1 = y1.end();
	y2.start();
	mergeSort(&myar);
	struct timespec t2 = y2.end();

	cout << "Threadsort:\t" << (t1.tv_sec * 1000000000) + t1.tv_nsec << "\n";
	
	cout << "Mergesort:\t" << (t2.tv_sec * 1000000000) + t2.tv_nsec << "\n";
	return 0;
}
