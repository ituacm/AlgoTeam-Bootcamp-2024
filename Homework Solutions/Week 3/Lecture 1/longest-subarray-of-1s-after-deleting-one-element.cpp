// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();    // Get the size of the input array
        int maxLength = 0;         // Variable to track the maximum length of the subarray
        int fast = 0, slow = 0;    // Two pointers for the sliding window
        int currentZeroCount = 0;  // Counter for the number of zeros in the current window
        int lastZeroIndex = -1;    // Store the index of the last encountered zero

        // Iterate through the array with the fast pointer
        for (; fast < size; fast++) {
            if (nums[fast] == 0) {   // If the current element is zero
                currentZeroCount++;  // Increment the zero count

                if (currentZeroCount == 2) {   // If there are two zeros in the window
                    slow = lastZeroIndex + 1;  // Move the slow pointer just past the last zero
                    currentZeroCount--;        // Decrement the zero count back to 1
                }
                lastZeroIndex = fast;  // Update the last zero index to the current zero
            }
            maxLength = max(maxLength, fast - slow);  // Update the maximum length of the subarray found so far
        }

        return maxLength;  // Return the length of the longest subarray
    }
};
