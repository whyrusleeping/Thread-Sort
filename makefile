all:
	g++ -std=gnu++0x -pthread -lrt main.cpp ThrMergeSort.cpp yardstick.cpp -o tmsort

