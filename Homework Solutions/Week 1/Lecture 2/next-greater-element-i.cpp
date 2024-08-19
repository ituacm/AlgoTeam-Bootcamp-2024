// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/next-greater-element-i/

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // map to store the next greater element for each number in nums2
        unordered_map<int, int> nextGreaterNumber;
        // stack to help find the next greater element
        stack<int> s;

        // iterate through each number in nums2
        for (auto num : nums2) {
            // while stack is not empty and the current number is greater than the stack's top element
            while (!s.empty() && s.top() < num) {
                // the next greater element for the stack's top is the current number
                nextGreaterNumber[s.top()] = num;
                // remove the top element
                s.pop();
            }
            // push the current number onto the stack
            s.push(num);
        }

        // initialize result vector as the exact copy of nums1
        vector<int> result = nums1;
        // for each number in the result vector
        for (auto& num : result)
            // replace the number with its next greater element or -1 if not found
            // 0 is the default return value and minimum value in vectors, therefore it is safe
            num = nextGreaterNumber[num] ? nextGreaterNumber[num] : -1;
        return result;
    }
};
