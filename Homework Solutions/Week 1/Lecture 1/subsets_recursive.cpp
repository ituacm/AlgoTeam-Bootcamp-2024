// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/subsets/

/*
    In this approach, we take advantage of the property of the subsets,
    in which each element in the nums array exists in half of the subsets
    and does not exist in the other half, meaning that we can take each value
    or do not take and proceed next value in the nums array.
    In a small example, it can be shown as:

    decide for 0. index     [1]        []    take 1 or do not take.
    decide for 1. index [1,2]  [1]   [2] []  take 2 or do not take.
    
    If we see that we explore all the elements in the nums array, 
    we should add that subset to solution subsets.
*/

// Time complexity: O(2^n)
// Space complexity: O(n * 2^n), 

class Solution {
public:
    vector<vector<int>> all_subsets;
    void recursive_subset(vector<int> &n, vector<int> &cs, int i){
        int size = n.size();
        if(i == size){  // if we explore all the elements add the subset in solution array.
            all_subsets.push_back(cs);
            return;
        }
        cs.push_back(n[i]);  // add the element.
        recursive_subset(n, cs, i+1);
        cs.pop_back(); // do not add the element 
        recursive_subset(n, cs, i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr_subset;
        recursive_subset(nums, curr_subset, 0);

        return all_subsets;
    }
};
