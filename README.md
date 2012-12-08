# ThreadSort
## Why?
In my 223 class our professor noted that while quiksort is normally faster than mergesort, mergesort could be threaded easily. A friend of mine said that I should implement that, So I did.

## Only Four extra threads?
While writing this I tried having it spawn more threads recursively while the array-subset was greater than a certain size. This led me to conclude two things,
One: Recursively calling threads is a bad idea, and it breaks things.
Two: Spawning more threads than you have processors for actually slows things down. (who knew?)

## How To
To run this yourself, I first reccomend that you have linux (I used linux libraries in my main.cpp for timing), users of Windows will have to write their own main function (or maybe ill write in some cross platform code laster)  
First Clone this project from github:

    git clone git://github.com/whyrusleeping/Thread-Sort.git

Then build it:

    cd Thread-Sort/; make

And run it:

    ./tmsort

(optional command line argument of size of array to test on, defaults to 2000000)
