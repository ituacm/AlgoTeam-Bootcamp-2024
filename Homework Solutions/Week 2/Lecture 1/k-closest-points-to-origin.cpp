// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand(time(NULL));                 // Seed the random number generator
        int l = 0, r = points.size() - 1;  // Initialize left and right pointers

        // Perform a modified quickselect to find the k closest points
        while (l < r) {
            int pivotIndex = partition(points, l, r);  // Partition the array
            if (pivotIndex == k - 1)                   // If pivotIndex is k-1, we've found the k closest points
                break;
            else if (pivotIndex < k - 1)  // If pivotIndex is less than k-1, search in the right half
                l = pivotIndex + 1;
            else                          // If pivotIndex is greater than k-1, search in the left half
                r = pivotIndex - 1;
        }

        // Return the first k points
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

   private:
    // Partition the array around a pivot
    int partition(vector<vector<int>>& points, int l, int r) {
        int selectedPivotIndex = (rand() % (r - l + 1)) + l;                       // Select a random pivot index
        int pivotDistanceToOrigin = distanceToOrigin(points[selectedPivotIndex]);  // Compute the distance of the pivot to the origin
        swap(points[selectedPivotIndex], points[r]);                               // Move pivot to end
        int pivotIndex = l;

        // Reorder elements around the pivot
        for (int i = l; i < r; i++)
            if (distanceToOrigin(points[i]) <= pivotDistanceToOrigin)
                swap(points[pivotIndex++], points[i]);  // Move elements smaller than pivot to the left

        swap(points[pivotIndex], points[r]);  // Move pivot to its final position
        return pivotIndex;
    }

    // Calculate the squared distance of a point from the origin
    inline int distanceToOrigin(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};
