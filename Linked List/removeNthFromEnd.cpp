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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fast = head;
    while (n--) fast = fast->next;
    auto curr = head;
    while (fast) {
        fast = fast->next;
        curr = (curr)->next;
    }
    fast = curr;
    curr = (curr)->next;
    delete fast;
    return head;
    }
};