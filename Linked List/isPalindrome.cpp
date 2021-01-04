/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?


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
    ListNode* Reverse(ListNode* &head) {
        ListNode*prev=NULL;
        ListNode*current=head;
        ListNode*Next=NULL;
        while(current!=NULL){
            Next=current->next;
            current->next=prev;
            prev=current;
            current=Next;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL || (head->next->next==NULL && head->val==head->next->val)){
            return true;
        }
        if(head->next->next==NULL && (head->val!=head->next->val)){
            return false;
        }
        ListNode* FastPtr = head;
        ListNode* SlowPtr = head;
        //reverse linked list from half of linked list
        while(FastPtr->next!=NULL && FastPtr->next->next!=NULL){
            FastPtr=FastPtr->next->next;
            SlowPtr=SlowPtr->next;
        }
        SlowPtr->next = Reverse(SlowPtr->next);
        SlowPtr = SlowPtr->next;
        //match from starting and half od the linked list if they match
        ListNode* TempSlow = SlowPtr;
        while(TempSlow!=NULL){
            if(head->val!=TempSlow->val){
                return false;
            }
            head = head->next;
            TempSlow = TempSlow->next;
        }
        return true;
    }
};
/*
O(N) & O(1) space
Runtime: 20 ms, faster than 93.58% of C++ online submissions for Palindrome Linked List.
Memory Usage: 14.5 MB, less than 55.90% of C++ online submissions for Palindrome Linked List.

*/