// Author: Ali Emre Kaya

// Time complexity: O(N)
// Space complexity: O(N)
// Question Link: https://leetcode.com/problems/valid-parentheses

/*
Step-by-Step Solution:
1. Initialize a stack to keep track of the opening brackets.
2. Iterate through each character in the string:
   - If the character is an opening bracket ('(', '{', '['), push it onto the stack.
   - If the character is a closing bracket (')', '}', ']'):
     - Check if the stack is empty or if the top of the stack does not match the corresponding opening bracket. If either condition is true, return false.
     - If the top of the stack matches the corresponding opening bracket, pop the top of the stack.
3. After processing all characters in the string, check if the stack is empty. If it is empty, return true indicating that the string is valid. Otherwise, return false.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // Iterate through each character in the string
        for (auto i : s) {
            // If the character is an opening bracket, push it onto the stack
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else {
                // If the stack is empty or the top of the stack does not match the closing bracket, return false
                if (st.empty() || (st.top() == '(' && i != ')') || (st.top() == '{' && i != '}') || (st.top() == '[' && i != ']')) {
                    return false;
                }
                // If the closing bracket matches, pop the top of the stack
                st.pop();
            }
        }
        // If the stack is empty at the end, all brackets were matched correctly
        return st.empty();
    }
};