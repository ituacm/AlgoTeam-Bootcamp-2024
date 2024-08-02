// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/majority-element/

// Time complexity: O(n logn)
// Space complexity: O(1)

/*
    The main idea here is that, majority element must be the mid element of a sorted array.
    Why? Because even if it is the smallest element or the largest element,
    it will appear more than n/2 times. Example: 1 1 1 2 2 or 1 1 2 2 2.
    Think it as you have n/2 + 1 sized subarray consisting the same elements and
    trying to put a place that no element will appaer in the mid index.
    That is impossible. So, basically sort the array and return the mid element.    
*/
// note: using quick sort makes runtime too much because of its worst case scenario O(n^2). Using built-in sort
// is much faster than using our quick sort function. Check out how cpp sort works:
// https://www.geeksforgeeks.org/introsort-cs-sorting-weapon/

class Solution {
public:
    // generates random number between left and right both included.
    int rand_num_generator(int left, int right){
        return (rand() % (right - left + 1)) + left;
    }

    void quick_sort(vector<int> &nums, int left, int right){
        // if left > right or right == left, meaning that 1 single element to sort, no need
        // to continue. Just return.
        if(left >= right)
            return;
        // quick sort goes O(n^2) in the worst case. One way to eleminate the worst case
        // is choosing pivot index randomly. 
        int rand_right_index = rand_num_generator(left, right);
        swap(nums[rand_right_index], nums[right]);
        // put the pivot_num to the right-most index.

        int i = left-1;
        int j = left;
        int pivot_num = nums[right];
        
        // this process puts the elements smaller than the pivot_num to the left handside of
        // the index which our pivot_index will be placed at the end. 
        for(; j < right; j++){
            if(nums[j] < pivot_num){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        i++; // correct place for our pivot_num
        swap(nums[i], nums[j]);
        // We are now guarenteed that elements lying in the left of the pivot_num are smaller
        // than the pivot_num and elements lying in the right are greater than the pivot_num.
        // so just call the same function for the left and the right subarrays.
        quick_sort(nums, left, i-1);
        quick_sort(nums, i+1, right);
    }

    int majorityElement(vector<int>& nums) {
        srand(time(NULL));
        quick_sort(nums, 0, nums.size()-1);
        return nums[nums.size() / 2];
    }
};
