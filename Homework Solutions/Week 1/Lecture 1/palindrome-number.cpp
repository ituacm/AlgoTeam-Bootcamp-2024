// Author: Rojen Arda Sesen
// Question Link: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        // Convert the integer to a string to avoid
        // expensive mathematical operations. 
        string s = to_string(x);
        return recursion(s, 0, s.length() - 1);
    }

    // With the help of this function, we will recurse over
    // the entire string, while l and r will point to our 
    // locations on the string 
    bool recursion(const string& s, const int l, const int r) {
        // Return true if our left index exceeds right index. 
        // If the characters pointed by left or right are not
        // the same, this means that the string is not a 
        // palindrome. So if s[l] != s[r], the expression will
        // return false without recursing furhter (see short-
        // circuit evaluation). If the characters are the same,
        // the function will call itself with incremented l 
        // value and decremented r value.
        return (l >= r || (s[l] == s[r] && recursion(s, l + 1, r - 1)));
    }
};