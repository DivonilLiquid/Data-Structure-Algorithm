/*
QUESTION:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

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
    void AddAtEnd(ListNode* &head,ListNode*NextElement){
        if(head==NULL){
            head=NextElement;
            head->next=NULL;
        }
        else{
            ListNode* temp = head;
            while(temp!=NULL){
                temp=temp->next;
            }
            temp->next=NextElement;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //final answer will be stored in this list 
        ListNode* NewLinkedList = new ListNode(0);
        
        //intialise k nodes and every node(i) should point to lists(i) head, calculate k
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*,vector<ListNode*>, decltype(cmp)> mypq(cmp);
        
        for(int i = 0; i < lists.size(); i++)
            if(lists[i] != nullptr) 
                mypq.push(lists[i]);

        //initialised priority queue
        // now enter all the k elements in a priority queue
        
        
        // now top element of priority queue will be least 
        // do it until priority queue is not empty
        ListNode* cursor = NewLinkedList;
        while(!mypq.empty()){
            ListNode* curr = mypq.top();
            mypq.pop();
            if(curr->next != nullptr) mypq.push(curr->next);
            cursor->next = curr;
            cursor = curr;
            // then let the kth pointer of that place moves forward
            // then pop it out from priority queue
            //then add the next kth pointer value in that priority queue
        }
        return NewLinkedList->next;
    }
};