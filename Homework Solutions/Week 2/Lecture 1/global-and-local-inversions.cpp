// Author: Ali Emre Kaya

// Time Complexity: O(n logn)
// Space Complexity = O(n)
// Question Link: https://leetcode.com/problems/global-and-local-inversions

/*
Approach: 
    We are asked to check the equality of two different values, local inversion and global inversion. 
        - We find the local inversion value by using the condition (nums[i] > nums[i+1]) with a loop of O(n) time complexity. 
        - Although there are different ways to find the global inversion, since this assignment is part of the divide and concuer course, 
        we will solve it using merge sort. When doing merge sort, if the value in the left vector is greater than the value in the right vector, 
        which means that the larger indexes of the left vector are also greater than the current right value, 
        so we find some of the global inversions using this operation (partly_gi += leftSize - leftPointer).

In the end of the file, leetcode examples explained.
*/

/*
There are two ifferent solution with merge sort algorithm

First Solution: Creates separate left and right vectors during the merge step. 
    This involves copying subarrays from the original array to the new vectors and then merging them. 
    This copying operation increases both time and space complexity, making the merge step slower due to additional overhead.
Second Solution: Uses a single temporary vector temp to perform the merge. 
    This avoids creating new vectors for each merge, reducing both memory usage and the time required for copying data. 
    This approach is more efficient as it directly merges elements into the temp vector and then copies them back to the original array.
*/

// First solution
// merge sort template: https://favtutor.com/blogs/merge-sort-cpp
class Solution {
public:
    // The merge function merges two sorted subarrays and counts the global inversions.
    long long int merge(vector<int>& arr, vector<int>& left, vector<int>& right, int start) {
        long long int partly_gi = 0;
        int leftPointer = 0, rightPointer = 0;
        int leftSize = left.size(), rightSize = right.size();
        int arrayPointer = start;  // Start from the index 'start' in the original array

        // Merge elements from left and right subarrays back into arr
        while (leftPointer < leftSize && rightPointer < rightSize) {
            if (left[leftPointer] <= right[rightPointer]) {
                arr[arrayPointer++] = left[leftPointer++];
            } 
            else { // global inversion case, nums[i] > nums[j]
                partly_gi += leftSize - leftPointer; 
                arr[arrayPointer++] = right[rightPointer++];
            }
        }
        // Copy remaining elements to arr
        while (leftPointer < leftSize) {
            arr[arrayPointer++] = left[leftPointer++];
        }
        while (rightPointer < rightSize) {
            arr[arrayPointer++] = right[rightPointer++];
        }

        return partly_gi;
    }

    // Recursive Merge Sort function to sort the array
    long long int recursiveMergeSort(vector<int>& arr, int left, int right) {
        // Total global inversion count
        long long int global_inv = 0; 

        // Base case: if the array contains one or no elements, return 0 and exit
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
 
        // Recursively sort the left and right halfs and count its global inversions
        global_inv += recursiveMergeSort(arr, left, mid);
        global_inv += recursiveMergeSort(arr, mid + 1, right);
        
        // Create left and right subarrays from the original array
        vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

        // Merge the two halves and count any new global inversions during merging
        global_inv += merge(arr, leftArr, rightArr, left);

        return global_inv;
    }

    bool isIdealPermutation(vector<int>& nums) {
        long long int local_inv = 0;
        long long int global_inv = 0;

        // Count the local inversions in the array
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                local_inv += 1;
            }
        }

        // Count the global inversions in the array using a modified merge sort
        global_inv = recursiveMergeSort(nums, 0, nums.size() - 1);
        
        return (global_inv == local_inv);
    }
};

// Second Solution
class Solution {
public:
    long long int recursiveMergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if(left == right){
            return 0;
        }

        int mid = left + (right - left) / 2;

        long long int inversions = 0;

        inversions += recursiveMergeSort(nums, temp, left, mid);
        inversions += recursiveMergeSort(nums, temp, mid + 1, right);
        inversions += merge(nums, temp, left, mid, right);

        return inversions;
    }

    int merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int leftPointer = left, rightPointer = mid + 1, tempPointer = left, inversions = 0;

        while(leftPointer <= mid && rightPointer <= right) {
            if(nums[leftPointer] <= nums[rightPointer])
                temp[tempPointer++] = nums[leftPointer++];
            else {
                temp[tempPointer++] = nums[rightPointer++];
                inversions += mid - leftPointer + 1;
            }
        }

        while(leftPointer <= mid)
            temp[tempPointer++] = nums[leftPointer++];
        while(rightPointer <= right)
            temp[tempPointer++] = nums[rightPointer++];

        for(int leftPointer = left ; leftPointer <= right; leftPointer++)
            nums[leftPointer] = temp[leftPointer];

        return inversions;
    }

    bool isIdealPermutation(vector<int>& nums) {
        long long int local_inv = 0;
        long long int global_inv = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1])
                local_inv++;
        }

        vector<int> temp(nums.size());
        global_inv = recursiveMergeSort(nums, temp, 0, nums.size() - 1);
        return local_inv == global_inv;
    }
};

/*
Example 1:
Input: [1, 2, 0]

Counting Local Inversions:
- Compare 1 and 2 -> No local inversion
- Compare 2 and 0 -> Yes, local inversion
Total Local Inversions: 1

Counting Global Inversions using Merge Sort:
1. Divide [1, 2, 0] -> [1, 2] and [0]
2. Recursively sort and count inversions in [1, 2]:
   - Divide [1, 2] -> [1] and [2]
   - Merge [1] and [2] -> No inversions
   Total: 0 inversions in [1, 2]
3. Merge [1, 2] and [0]:
   - 0 < 1 -> Count 2 inversions
   - 0 < 2 -> Count 1 more inversion
   Total: 3 inversions in [1, 2, 0]
Total Global Inversions: 3

Result: Local Inversions (1) != Global Inversions (3), so the array is not an ideal permutation.


Example 2:
Input: [1, 0, 2]

Counting Local Inversions:
- Compare 1 and 0 -> Yes, local inversion
- Compare 0 and 2 -> No local inversion
Total Local Inversions: 1

Counting Global Inversions using Merge Sort:
1. Divide [1, 0, 2] -> [1, 0] and [2]
2. Recursively sort and count inversions in [1, 0]:
   - Divide [1, 0] -> [1] and [0]
   - Merge [1] and [0] -> Count 1 inversion
   Total: 1 inversion in [1, 0]
3. Merge [1, 0] and [2] -> No further inversions
   Total: 0 inversions in [1, 0, 2]
Total Global Inversions: 1

Result: Local Inversions (1) == Global Inversions (1), so the array is an ideal permutation.
*/