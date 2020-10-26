/**
Question:
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
     ListNode* hasCycle(ListNode *head) {
        ListNode* FastPtr = head;
        ListNode* SlowPtr = head;
        while(FastPtr != NULL && FastPtr->next != NULL){
            FastPtr = FastPtr->next;//->next;
            SlowPtr = SlowPtr->next;
            FastPtr = FastPtr->next;
            //when fast and slow pointers encounter each other
            if(FastPtr == SlowPtr){
                return FastPtr;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        //detect if there's any cycle or not
        ListNode* FastPtr = hasCycle(head);
        if(FastPtr == NULL || head == NULL){
            return NULL;
        }
        //put slow ptr at head
        ListNode* SlowPtr = head;
        //now both pointer will take one step at a time
        while(FastPtr != SlowPtr){
            FastPtr = FastPtr->next;
            SlowPtr = SlowPtr->next;
        }
        // the place where they both encouter each other 
        // is the desired node
        return FastPtr;
    }
};