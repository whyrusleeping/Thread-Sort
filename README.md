# ThreadSort
## Why?
In my 223 class our professor noted that while quiksort is normally faster than mergesort, mergesort could be threaded easily. A friend of mine said that I should implement that, So I did.

## How To
To run this yourself, I first recommend that you have linux (I used linux libraries in my main.cpp for timing), users of Windows will have to write their own main function (or maybe ill write in some cross platform code later)  
First Clone this project from github:

    git clone git://github.com/whyrusleeping/Thread-Sort.git

Then build it:

    cd Thread-Sort/; make

And run it:

    ./tmsort 100000000 2

command line arguments are; size of the test array, and maximum recursive threading depth. (best set to 1 or 2 unless you have an 8 core+ machine)
