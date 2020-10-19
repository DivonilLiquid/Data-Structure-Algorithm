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
    ListNode* swapPairs(ListNode* head) {
        	ListNode* cur = head;
            while(cur!=nullptr and cur->next!=nullptr){
                int val = cur->val;
                cur->val = cur->next->val;
                cur->next->val = val;
                if (cur==nullptr || cur->next==nullptr || cur->next->next==nullptr){
                    break;
                }
                cur = cur->next->next;
            }
            return head;
    }
};