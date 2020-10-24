/**
Question
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    int CalculateLengthOfLinkedList(ListNode* head){
        int Count = 0;
        while(head){
            head = head->next;
            Count++;
        }
        return Count;
    } 
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        // Function to calculate length of a linked list
        int Length = CalculateLengthOfLinkedList(head);
        //deal with k if it's greater then n
        
        if(k > Length){
            k = k % Length;
        }
        if(k == 0 || k == Length || Length == 1){
            return head;
        }
        
        // 2 slow pointer and 1 fast pointer to break list
        ListNode* SlowPointer = head;
        ListNode* FastPointer = head;
        //fast pointer should be k step ahead
        while(k--){
            FastPointer = FastPointer->next;
        }
        while(FastPointer->next != NULL){
            FastPointer = FastPointer->next;
            SlowPointer = SlowPointer->next;
        }
        //make 1 slowpointer head and fast pointer is tail of that head
        ListNode* NewHead = SlowPointer->next;
        //connect that tail to original head of linked list
        FastPointer->next = head;
        SlowPointer->next = NULL;
        return NewHead;
    }
};