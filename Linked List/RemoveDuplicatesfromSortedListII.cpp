/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
            1->2->3->3->3->4->4->5
                  ^     ^
                  |     |
                  C     N
       if(C->val==C->next->val)
            N = C->next
                  while N->val == N->next->val
                  N=N->next
            C->next = N->next
                  
    */
    ListNode* deleteDuplicates(ListNode* &head) {
        if(!head||!head->next)
            return head;
        ListNode *newhead=0,**phead=&newhead;
        //phead pointer to new head pointer
        while(head)
        {
            if(head->next && head->val==head->next->val)
            {
                //skip all nodes has duplicate value
                int dupval=head->val;
                while(head && head->val==dupval)
                    head=head->next;
                continue;
            }
            //assign and advance phead
            else {
                *phead=head; 
                phead=&((*phead)->next);
                //phead = phead->next
            }
            head=head->next;
        }
        *phead=0;// point the next of last node to NULL
        return newhead;
    }
};
/*
Runtime: 8 ms, faster than 90.21% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 11.6 MB, less than 75.58% of C++ online submissions for Remove Duplicates from Sorted List II.

*/