// Author: Ali Emre Kaya
// Question: https://leetcode.com/problems/find-mode-in-binary-search-tree/

// Time complexity: O(n) = O(node count)
// Space complexity: O(1)

/*
This problem is asking you to find the mode(s) of a binary search tree (BST). 
The mode of a dataset is the value that appears most frequently. 
If there are multiple values that have the same highest frequency, all of them should be returned.

Approach: 
-- Inorder Traversal
Inorder traversal of a BST processes nodes in ascending order. 
This allows us to easily detect and count occurrences of each value, 
as we can compare the current node's value directly with the previous node's value.

-- Tracking Frequencies
We maintain three key variables:
    currFreq : This tracks the frequency of the current node value.
    maxFreq : This keeps the highest frequency encountered so far.
    preCursor : This stores the value of the previous node to facilitate frequency calculation.
As we traverse the BST, we update currFreq whenever the current value matches the previous one. 
If currFreq surpasses maxFreq, we clear the result vector and update it with the new mode. 
If currFreq equals maxFreq, we add the current value to the result vector.
*/

class Solution {
public:
    int maxFreq = 0, currFreq = 0, preCursor = INT_MIN;
    vector<int> res;

    vector<int> findMode(TreeNode *root){
        inorderTraversal(root);
        return res;
    }

    void inorderTraversal(TreeNode *root){
        if (root == NULL) return; // Stop condition
        // Traverse with inorder
        inorderTraversal(root->left); 
        isMax(root);
        inorderTraversal(root->right);
    }

    void isMax(TreeNode *root){
        if (preCursor == root->val) currFreq++;
        else currFreq = 1;
        // If currFreq is bigger, then delete other's from array and prepare array with new maxFreq
        if (currFreq > maxFreq){
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }
        // If currFreq == maxFreq, that mean there is two value with same freq, 
        // but if next root->val is same with current root->val, then this array will colapse.
        else if (currFreq == maxFreq){
            res.push_back(root->val);
        }
        preCursor = root->val;
    }
};