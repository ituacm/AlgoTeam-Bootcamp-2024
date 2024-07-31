// Author: Ali Emre Kaya

// Time complexity: O(N)
// Space complexity: O(1)
// Question Link: https://leetcode.com/problems/reverse-linked-list

/* 
Approach: To reverse a singly linked list, we need to change the direction of the links between the nodes. 
We can achieve this by iterating through the list and adjusting the pointers accordingly.

- We start with the head of the list and initialize two pointers: prev and forw to NULL.
- During each iteration of the loop, we:
  - Save the next node in forw.
  - Reverse the current node's pointer by making it point to prev.
  - Move prev to the current node and head to the next node.
- Once we reach the end of the list (head becomes NULL), prev will point to the new head of the reversed list.
- Finally, we return prev.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* forw = NULL;

        while(head != NULL){
            forw = head->next;
            head->next = prev;
            prev = head;
            head = forw;
        }
        return prev;
    }
};

/*
   For every end of the while loop for the example (1->2->3->4)

   Initial:
   NULL <- 1   2 -> 3 -> 4 -> NULL
      |    |
     prev head

   Iteration 1:
   NULL <- 1   2 -> 3 -> 4 -> NULL
           |   |
          prev head

   Iteration 2:
   NULL <- 1 <- 2   3 -> 4 -> NULL
                |    |
              prev head

   Iteration 3:
   NULL <- 1 <- 2 <- 3   4 -> NULL
                     |    |
                    prev head

   Iteration 4:
   NULL <- 1 <- 2 <- 3 <- 4   NULL
                         |    |
                        prev head
*/