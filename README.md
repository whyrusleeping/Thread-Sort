# ThreadSort
## Why?
In my 223 class our professor noted that while quiksort is normally faster than mergesort, mergesort could be threaded easily. A friend of mine said that I should implement that, So I did.

## Only Four extra threads?
While writing this I tried having it spawn more threads recursively while the array-subset was greater than a certain size. This led me to conclude two things,
One: Recursively calling threads is a bad idea, and it breaks things.
Two: Spawning more threads than you have processors for actually slows things down. (who knew?)

