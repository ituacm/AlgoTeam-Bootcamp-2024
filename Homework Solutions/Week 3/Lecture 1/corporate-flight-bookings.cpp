// Author: Ali Emre Kaya
// Time complexity: O(n+m)
// Space complexity: O(n)
// Question link: https://leetcode.com/problems/corporate-flight-bookings/

/*
Aproach: 
    This solution uses the difference array technique to efficiently manage range updates. 
    
    The idea is to apply the seat changes directly at the start and end points of the booking 
    range, which are later converted into the final seat counts using a prefix sum.
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // Initalize res  with (n, 0), because using push_back is not works for this quest,
        // indexes should reachable for all n values
        vector<int> res(n,0);

        // Prepare array for prefix summing: O(m)
        for(vector<int> booking : bookings) {
            res[booking[0] - 1] += booking[2]; 
            if(booking[1] < n) {
                res[booking[1]] -= booking[2]; 
            }
        }

        // Prefix sum: O(n)
        for(int i = 1; i < res.size(); ++i)
            res[i] += res[i-1];

        return res;
    }
};

/* 
Walkthrough for leetcode's example:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10, 55, 45, 25, 25]

Explanation:

Firstly, initalzie res with all zeros:
    res = [0, 0, 0, 0, 0]

Then, for each booking, we update the `res` array using the difference array technique:

1. Booking [1, 2, 10]:
    Resulting `res`: [10, 0, -10, 0, 0]

2. Booking [2, 3, 20]:
    Resulting `res`: [10, 20, -10, -20, 0]

3. Booking [2, 5, 25]:
    Resulting `res`: [10, 45, -10, -20, 0]

After processing all bookings, we calculate the prefix sum to obtain the final seat counts for each flight:
res = [10, 55, 45, 25, 25]
*/