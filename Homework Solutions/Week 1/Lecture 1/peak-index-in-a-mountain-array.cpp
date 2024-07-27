// Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/


/*
The array is divided into two regions: ascending and descending.
The question is finding the peak point where the transition between these two regions occurs.


Linear search could be done, but this costs O(N). Let's see if a binary search might work as a better solution.


Our array is actually like this:
***ASC*** | PEAK | ***DESC***


The main goal is to reach PEAK. For all iterations, if I am in the DESC field I have to go left and vice versa.
So when will I reach the result?


Let's try an example
You update the left and right pointers for all iterations.
***ASC*** | PEAK | ***DESC***
|                           |
|                   |
   |               |
       |           |
       |       |		
       |    |
           ||


The pointers meet in the PEAK if you construct your binary search correctly(exit loop if left < right).
(Give a numerical example and try)


When I exit from binary search loop, both pointers point PEAK. I could return one of them.


Time complexity: O(logN)
Space complexity: O(1)
*/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        // KINDLY REMINDER: If you declare a variable and 
        // do not initialize it(assign it a value),
        // the variable serves you the value in the 
        // memory block it points to, which is random for us.
        // 
        // Initializing a variable with an initial value
        // is good practice because unexpected random values
        // are dangerous.
        int left=0, right=arr.size();
        // A safe way of finding the middle of two pointers.
        int mid = left + (right-left)/2;

        while (left < right) {
            mid = left + (right-left)/2;

            if (arr[mid+1] > arr[mid])
                // COMMON MISTAKE: Assigning mid to left (left=mid;)
                // means you include the mid value to the interval of
                // the next iteration. This may change anything in
                // your implementation, but it may cause various problems 
                // such as infinite loops for different questions.
                // (Also causes an infinite loop in this solution, try it.)
                left = mid+1;

            else
                right = mid;
        }

        return left;
    }
};