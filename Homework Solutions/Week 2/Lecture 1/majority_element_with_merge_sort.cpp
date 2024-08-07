// Author: Ali Eren Çiftçi
// Editorial: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/majority-element/

/*
 * There are many solutions to this question but this specific
 * solution focuses on the solution with merge sort.
 * THe question here asks to find the number in the array
 * which appears more than 'n/2' times. This can be done
 * through sorting the array first and then looking at the middle
 * element as it would always be the element that appears 'n/2' times.
 *
 * First, we sort the elements recursively using merge sort.
 * Diving each subarray into two subarrays of same length and
 * regrouping these subarrays into one by sorting them in 'O(n)' time.
 */

class Solution {
public:
    void merge_sort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;

	// finding the middle point of the subarray
        int m = (l + r) / 2;

	// recursively re-dividing the array into subarrays
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

	// and sorting & combining them into one array
        merge(arr, l, m, r);
    }

    void merge(vector<int> &arr, int l, int m, int r)
    {
	// left and right subarrays to sort
        vector<int> lsa(arr.begin() + l, arr.begin() + m + 1);
        vector<int> rsa(arr.begin() + m + 1, arr.begin() + r + 1);

	// left and right pointers as well as the pointer of the array 'i'
        int i = l;
        int lp = 0, rp = 0;

	// getting the elements in the correct order until one subarray is finished
        while(lp < lsa.size() && rp < rsa.size())
        {
            if(lsa[lp] >= rsa[rp])
                arr[i] = rsa[rp++];
            else
                arr[i] = lsa[lp++];
            i++;
        }

	// getting the rest of the elements in the subarrays accordingly
        while(lp < lsa.size())
            arr[i++] = lsa[lp++];
        while(rp < rsa.size())
            arr[i++] = rsa[rp++];
    }

    int majorityElement(vector<int>& nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return nums[nums.size()/2];
    }
};
