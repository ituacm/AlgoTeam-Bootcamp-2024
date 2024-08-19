// Author: Ali Emre Kaya
// Time complexity: O(4^n / √n) -> calculated with catalan number [C_n = (1 / (n + 1)) * C(2n,n)]
// Space complexity: O(n) -> comes from string& curr
// Question link: https://leetcode.com/problems/generate-parentheses/

/*
Approach:
    The problem requires generating all combinations of well-formed parentheses for a given number `n`, 
        where `n` represents the number of pairs of parentheses. 
    The approach involves using backtracking to explore all possible combinations of parentheses. 

1. Base Case (if): When both the number of open and close parentheses used (`left` and `right`) equals `n`, a valid combination is formed, and we add it to the result list.

2. Recursive Case (else):
    - If `left` (number of '(' used) is less than `n`, we can add an open parenthesis and recursively call the function with `left + 1`.
    - If `right` (number of ')' used) is less than `left`, we can add a close parenthesis and recursively call the function with `right + 1`. 
    This ensures that we only add a close parenthesis when it will still result in a valid combination.

By backtracking (undoing the last addition by `curr.pop_back()`), we explore all possible valid sequences. 
The recursion continues until all valid sequences are found.
*/

/*
In recursive algorithms, if we passed the `curr` string by value, a new copy of the string would be created each time the function is called. 
This could lead to significant memory usage, especially as the depth of recursion increases. 
By passing `curr` by reference, we modify the same string throughout the recursion, only changing its content as needed. 
This reduces memory overhead and improves performance.

Pass by reference: Memory -> 11.91mb (beats %88)
Pass by value:     Memory -> 16.14mb (beats %16)
*/

class Solution {
public:
    void helper(vector<string>& parentheses, int n, int left, int right, string &curr) {
        if (n == left && n == right) {
            parentheses.push_back(curr);
        }
        else {
            if (left < n) {
                curr.push_back('(');
                helper(parentheses, n, left+1, right, curr);
                curr.pop_back();
            }
            if (right < n && right < left) {
                curr.push_back(')');
                helper(parentheses, n, left, right+1, curr);
                curr.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;
        string curr = "";
        helper(parentheses, n, 0, 0, curr);
        return parentheses;
    }
};