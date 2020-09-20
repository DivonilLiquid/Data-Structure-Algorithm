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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* OddHead = NULL;
        ListNode* OddTail = NULL;
        ListNode* EvenHead = NULL;
        ListNode* EvenTail = NULL;
        bool IsItOdd=1;
        ListNode* Temp = head;
        while(Temp != NULL){
            if(IsItOdd){
                if(OddHead == NULL){
                    OddHead=Temp;
                    OddTail=Temp;
                }
                else{
                    OddTail->next = Temp;
                    OddTail = Temp;
                }
                Temp=Temp->next;
                OddTail->next = NULL;
            }
            else{
                if(EvenHead == NULL){
                    EvenHead=Temp;
                    EvenTail=Temp;
                }
                else{
                    EvenTail->next = Temp;
                    EvenTail = Temp;
                }
                Temp=Temp->next;
                EvenTail->next = NULL;
            }
            IsItOdd = !IsItOdd;
        }
        OddTail->next = EvenHead;
        return OddHead;
    }
};