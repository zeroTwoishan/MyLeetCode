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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * j = head;
        ListNode * k = head->next;
        ListNode * l = head->next->next;
        j->next = l;
        k->next = j;
        head = k;
        ListNode * i = j;
        j = l;
        k = (j ? j->next : nullptr);
        l = (k ? k->next : nullptr);
        while(j != nullptr && k != nullptr){
            j->next = l;
            k->next = j;
            i->next = k;
            i = j;
            j = l;
            k = (j ? j->next : nullptr);
            l = (k ? k->next : nullptr);
        }
        return head;
    }
};