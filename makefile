all:
	g++ -std=gnu++0x -pthread -lrt main.cpp yardstick.cpp -o tmsort

