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
    ListNode* removeElements(ListNode* head, int val) {
       /*
       *****MESSY CODE*****
       if(head == nullptr) return head;
        while(head->val == val && head->next != nullptr) head = head->next;
        if(head->val == val && head->next == nullptr) return head->next;
        ListNode * temp = head->next;
        ListNode * prev = head;
        while(temp){
            if(temp->val == val){
                temp = temp->next;
                if(temp != nullptr && temp->val == val) continue;
                prev->next = temp;
            }
            if(temp != nullptr) temp = temp->next;
            prev = prev->next;
        }
        return head;*/
        // *****CLEANER CODE*****
        while (head != nullptr && head->val == val) head = head->next;
        if (head == nullptr) return head;
    
        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};