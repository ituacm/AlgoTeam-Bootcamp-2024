// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/is-subsequence/

// Time Complexity: O(n)
// Space Complexity: O(1)

/*
    We will declare 2 pointers for the strings, 
    one for each. Both will start from 0.
    We will increase the pointer for s if the characters
    pointed by both pointers are the same, if not, we will
    only increase the pointer for t. This way, if s is a 
    subsequence of t, pointer of s will reach its end 
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        for (int tp = 0; tp < t.length() && sp < s.length(); tp++) {
            if (s[sp] == t[tp]) sp++;
        }
        return sp == s.length();
    }
};

/*
### Example 1: ###
    Input: s = "abc", t = "ahbgdc"
    Output: true
    - Start loop:
    sp = 0, tp = 0
    s[sp] = 'a', t[tp] = 'a' --> increment sp and tp

    sp = 1, tp = 1
    s[sp] = 'b', t[tp] = 'h' --> increment tp

    sp = 1, tp = 2
    s[sp] = 'b', t[tp] = 'b' --> increment sp and tp

    sp = 2, tp = 3
    s[sp] = 'c', t[tp] = 'g' --> increment tp

    sp = 2, tp = 4
    s[sp] = 'c', t[tp] = 'd' --> increment tp

    sp = 2, tp = 5
    s[sp] = 'c', t[tp] = 'c' --> increment sp and tp

    sp = 3, tp = 6 --> Loop ends (the loop condition tp < tp.length() does not hold)
    Check if sp == sp.length() --> 3 == 3 --> True

### Example 2: ###
    Input: s = "axc", t = "ahbgdc"
    Output: false
    - Start loop:
    sp = 0, tp = 0
    s[sp] = 'a', t[tp] = 'a' --> increment sp and tp

    sp = 1, tp = 1
    s[sp] = 'x', t[tp] = 'h' --> increment tp

    sp = 1, tp = 2
    s[sp] = 'x', t[tp] = 'b' --> increment tp

    sp = 1, tp = 3
    s[sp] = 'x', t[tp] = 'g' --> increment tp

    sp = 1, tp = 4
    s[sp] = 'x', t[tp] = 'd' --> increment tp

    sp = 1, tp = 5
    s[sp] = 'x', t[tp] = 'c' --> increment tp

    sp = 1, tp = 6 --> Loop ends (the loop condition tp < t.length() does not hold)
    Check if sp == s.length() --> 1 != 3 --> False
*/
