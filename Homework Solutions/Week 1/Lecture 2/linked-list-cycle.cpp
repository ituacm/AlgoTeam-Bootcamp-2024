// Author: Fatih Baskın
// Question Link: https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // Average time complexity: O(n) (most of the time)
    // Space complexity: O(1)
    // Worst time complexity: O(n^2)
    bool hasCycle(ListNode *head)
    {
        // If there is no node, fast will be NULL and we will return false.
        // If there is only one node, fast->next will be NULL and we will return false.
        // If there is a cycle, fast will make a full cycle and meet slow at some point.
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    // Average time complexity: O(n)
    // Worst time complexity: O(n)
    // Space complexity: O(n)
    bool hasCycle2(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        // Insert all nodes to the set. If we see a node that is already in the set, we have a cycle.
        while (head != NULL)
        {
            if (visited.find(head) != visited.end())
            {
                return true;
            }
            // Insertion and checking have O(1) time complexity.
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};