// Author: Ali Emre Kaya
// Time complexity: O(k+n)
// Space complexity: O(1)
// Question link: https://leetcode.com/problems/maximum-average-subarray-i/


/*
Approach:
The problem is to find the contiguous subarray of length `k` that has the maximum average.

Sliding Window Technique: Use the sliding window approach to efficiently compute the sum of each subsequent subarray of size `k`. 
Instead of recalculating the sum from scratch for each window (which would be O(k) for each window),
update the sum by subtracting the element that slides out of the window and adding the new element that enters the window. 
This reduces the complexity to O(1) per window shift.
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_sum = 0;

        // Calculate max_sum with first k numbers
        for(int i = 0; i < k; i++){
            max_sum += nums[i];
        }

        double temp_sum = max_sum;

        // Calculate other windows
        for(int i = k; i < nums.size(); i++){
            // Do O(1) complexity sum operations,
            // instead of doing O(k) complexity loop
            temp_sum += nums[i] - nums[i - k];
            if(max_sum < temp_sum) max_sum = temp_sum;
        }

        return max_sum / k;
    }
};