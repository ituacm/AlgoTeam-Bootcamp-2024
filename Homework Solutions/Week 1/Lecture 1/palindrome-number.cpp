// Author: Rojen Arda Sesen
// Question Link: https://leetcode.com/problems/palindrome-number/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isPalindrome(int x) {
        /*
         * Convert the integer to a string to avoid
         * expensive mathematical operations. This 
         * will use O(n) space, where n is the number
         * of digits in the integer.
         */
        string s = to_string(x);
        return recursion(s, 0, s.length() - 1);
    }
    /*
     * With the help of this function, we will recurse over
     * the entire string, while l and r will point to our 
     * locations on the string 
     */
    bool recursion(const string& s, const int l, const int r) {
        /*
         * Return true if our left index exceeds right index. 
         * If the characters pointed by left or right are not
         * the same, this means that the string is not a 
         * palindrome. So if s[l] != s[r], the expression will
         * return false without recursing furhter (see short-
         * circuit evaluation). If the characters are the same,
         * the function will call itself with incremented l 
         * value and decremented r value.
         */
        return (l >= r || (s[l] == s[r] && recursion(s, l + 1, r - 1)));
    }
};


/*
Example 1:
Input: x = 121
Output: true
s = "121", l = 0, r = 2
     ^ ^
l is less than r, so we check if s[0] == s[2]
s[0] == s[2], so we call recursion(s, 1, 1)

s = "121", l = 1, r = 1
      ^
l is equal to r, so we return true. Remaining
part of the logic expression is not evaluated.
See short-circuit evaluation.

Example 2:
Input: x = 1234665321
s = "1234665321", l = 0, r = 9
     ^        ^
l is less than r, so we check if s[0] == s[9]
s[0] == s[9], so we call recursion(s, 1, 8)

s = "1234665321", l = 1, r = 8
      ^      ^
l is less than r, so we check if s[1] == s[8]
s[1] == s[8], so we call recursion(s, 2, 7)

s = "1234665321", l = 2, r = 7
       ^    ^
l is less than r, so we check if s[2] == s[7]
s[2] == s[7], so we call recursion(s, 3, 6)

s = "1234665321", l = 3, r = 6
        ^  ^
l is less than r, so we check if s[3] == s[6]
s[3] != s[6], so we return false. Remaining
part of the logic expression is not evaluated.
See short-circuit evaluation.

Output: false
*/