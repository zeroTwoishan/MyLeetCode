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
    ListNode* rotateRight(ListNode* head, int k) {        
    /*    ListNode * p = nullptr;
        ListNode * c = head;
        int len = 0;
        while(c!=nullptr){
            ListNode * n = c->next;
            c->next = p;
            p = c;
            c = n;
            len++;
        }
        k = k % len;
        while(k > 0){
            ListNode * temp = p;
            head->next = p;
            p = p->next;
            head = head->next;
            temp->next = nullptr;
            temp = p;
            k--;
        }
        ListNode * t = nullptr;
        while(p!=nullptr){
            ListNode * n = p->next;
            p->next = t;
            t = p;
            p = n;
        }
        return head;
    */
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        if(k == 0) return head;
        // make circular
        tail->next = head;
        int steps = len - k - 1;
        ListNode* newTail = head;
        while(steps--) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};