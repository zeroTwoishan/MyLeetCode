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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
    ListNode* i = head;
    ListNode* j = head->next;
    while (i != nullptr && j != nullptr) {
        while (j != nullptr && j->val == i->val) {
            j = j->next;
        }
        i->next = j;   
        i = j;         
        if (j != nullptr) j = j->next;  
    }
    return head;
    }
};