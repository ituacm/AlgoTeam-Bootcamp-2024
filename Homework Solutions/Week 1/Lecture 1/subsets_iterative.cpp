// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/subsets/

/*
    Explanation of this solution step by step:
    1-) add the empty set as a subset of the nums set.
    2-) reach each value in nums array with a for loop.
    3-) add i'th element to every subsets of the 2D solution vector
    4-) repeat step 3 until finishing the nums array.
    
    solution array step by step:
    1-> [[]] add empty set.
    2-> [[], [1]]  add 1 to empty set.
    3-> [[], [1], [2], [1,2]] add 2 to [] set and [1] set.
    4-> [[], [1], [2], [1,2], [3], [1,3], [1,2,3]] add 3 to every set in the solution array.
*/
// Time complexity: O(2^n)
// Space complexity: O(n * 2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> solution;
        // initialize the 2D solution vector with the empty subset.
        solution.push_back({});
        
        for(int i = 0; i < size; i++){
            int solution_size = solution.size();
            int curr_num = nums[i];
            for(int j = 0; j < solution_size; j++){
                vector<int> curr_subset = solution[j];
                curr_subset.push_back(curr_num);
                solution.push_back(curr_subset);
            }
        }

        return solution;
    }
};
