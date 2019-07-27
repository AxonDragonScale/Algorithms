// https://www.geeksforgeeks.org/external-sorting/

// Basic concept -
// 1. Divide the array/list into files that can fit in memory.
// 2. Sort each file seperately using appropriate sorting algorithm.
// 3. Use method similar to 'Merge k sorted arrays'. Put the 1st element of each file in a minHeap.
// 4. Every time pop from minHeap, put it in an answer file on disk, insert next element from the file which this
// element belonged to, into the minHeap.