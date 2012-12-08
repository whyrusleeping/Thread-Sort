all:
	g++ -std=gnu++0x -pthread -lrt -O3 main.cpp ThrMergeSort.cpp yardstick.cpp -o tmsort

