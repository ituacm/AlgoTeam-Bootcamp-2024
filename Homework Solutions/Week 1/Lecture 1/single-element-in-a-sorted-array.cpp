// Ali Emre Kaya
// Question Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

/*
The problem requires finding the single element in a sorted array where all other elements appear exactly twice.
We can find it with visiting all the element (brute force approach) until see sngle eleemnt, it's time complexity will be O(n) and will not pass.
Instead of brute force approach, we can use a binary search approach to solve this efficiently in O(log n) time.
 
Key Idea: If we look at the pairs in the array, the single element disrupts the pairing.
We exploit this by checking pairs and using binary search to find the single element.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // Calculate the middle index
            int mid = left + (right - left) / 2;

            // Ensure mid is even for proper pair comparison
            if (mid % 2 == 1) mid--; 

            /*
            1. condition: If nums[mid] equals nums[mid + 1], the single element is not in the left half.
            Move left boundary `left` to mid + 2 to skip this pair and continue the search.

            2. condition: If nums[mid] does not equal nums[mid + 1], the single element is either at mid or in the left half.
            Move right boundary `right` to mid to continue the search in the left half.
        
            (End of the file, you can see 2 example for these conditions)
            */
            if (nums[mid] == nums[mid + 1]) 
                left = mid + 2;
            else 
                right = mid;
        }

        // When left equals right, we have found the single element
        return nums[left];
    }
};

/*
1. condition's example: If nums[mid] equals nums[mid + 1], the single element is not in the left half.
    Move left boundary `left` to mid + 2 to skip this pair and continue the search.

    Example:
    Initial Array: [1, 1, 2, 2, 3, 4, 4]

    Step 1:
    - Initial state: left = 0, right = 6
    - Calculate mid = left + (right - left) / 2 = 0 + (6 - 0) / 2 = 3
    - Adjust mid to be even: mid = 2
    - nums[mid] = 2, nums[mid + 1] = 2
    - Since nums[mid] == nums[mid + 1], the single element is not in the left half.
    - Move left to mid + 2: left = 4
    - New range: [3, 4, 4]

    Step 2:
    - Now left = 4, right = 6
    - Calculate mid = 4 + (6 - 4) / 2 = 5
    - Adjust mid to be even: mid = 4
    - nums[mid] = 3, nums[mid + 1] = 4
    - Since nums[mid] != nums[mid + 1], move right to mid: right = 4

    Termination:
    - Now left = 4, right = 4
    - The single element is nums[left] = 3

2. condition's example: 

    Example:
    Initial Array: [1, 1, 2, 3, 3, 4, 4]

    Step 1:
    - Initial state: left = 0, right = 6
    - Calculate mid = left + (right - left) / 2 = 0 + (6 - 0) / 2 = 3
    - Adjust mid to be even: mid = 2
    - nums[mid] = 2, nums[mid + 1] = 3
    - Since nums[mid] != nums[mid + 1], the single element is either at mid or in the left half.
    - Move right to mid: right = 2
    - New range: [1, 1, 2]

    Step 2:
    - Now left = 0, right = 2
    - Calculate mid = 0 + (2 - 0) / 2 = 1
    - Adjust mid to be even: mid = 0
    - nums[mid] = 1, nums[mid + 1] = 1
    - Since nums[mid] == nums[mid + 1], the single element is not in the left half.
    - Move left to mid + 2: left = 2

    Termination:
    - Now left = 2, right = 2
    - The single element is nums[left] = 2
*/
