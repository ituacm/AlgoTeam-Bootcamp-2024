// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

/*
 * Given the address of the node to delete,
 * we can simply change the value and the next address
 * of the node stored in the ListNode structure as following.
 * This way, rather than deleting the node we can
 * change its variables accordingly and finish our code.
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Overwrite data of next node on current node.
        node->val = node->next->val;
        // Make current node point to next of next node.
        node->next = node->next->next;
    }
};
