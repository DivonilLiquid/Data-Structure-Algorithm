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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next_temp=nullptr;
        
        while(curr != nullptr)
        {
            next_temp = curr->next;    //Store address of next node
            curr ->next=prev;          //Point current node to previous node
            prev=curr;                 //Increment prev to +1 node
            curr=next_temp;            //Increment curr to +1 node
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==nullptr || head->next==nullptr)      //Base case
           return head;
        
        int count=1;
        ListNode* itr=head;
        while(itr!=nullptr && count<k){             //Iterate k number of elements which are to be reversed
            itr=itr->next;
            count++;
        }
        
        ListNode* head2;
        if(itr!=nullptr){                           //If list had k elements
            head2=itr->next;                        //keep address of next elemnt before breaking the link
            itr->next=nullptr;                      //Break the link after k elements
        }
        else
            return head;                            //If not enough elements return the head no need to do any work
              
        ListNode* ReversedHead=reverseList(head);   //Give LL of k elements for reversal
        head=ReversedHead;
        
        while(ReversedHead->next!=nullptr){         //Iterate to the end of reversed LL
            ReversedHead=ReversedHead->next;
        }
        
        ReversedHead->next=head2;                   //Connect it back to the broken point
        
        ListNode* Output = reverseKGroup(head2, k); //After doing work for first k elemnts call recusrion to do further work
        ReversedHead->next=Output;                  //Connect yor LL to the output returned by recursion
        return head;
        
        
    }
};