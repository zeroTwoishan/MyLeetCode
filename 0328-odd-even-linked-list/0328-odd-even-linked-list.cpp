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
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * feven = even;
        while(odd != nullptr && even != nullptr){
            if(odd->next != nullptr){
            odd->next = odd->next->next;
            odd = odd->next;
            }
            if(even->next != nullptr){
                even->next = even->next->next;
                even = even->next;
            }
            if((odd != nullptr && odd->next == nullptr) ||
            (even != nullptr && even->next == nullptr)) break;
        }
        odd->next = feven;
        if(even != nullptr)even->next = nullptr;
        return head;      
    }
};