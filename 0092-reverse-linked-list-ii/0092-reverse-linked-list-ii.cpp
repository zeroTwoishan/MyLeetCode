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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* ltprev = nullptr;
    ListNode* rtnext = nullptr;
    ListNode* lt = head;        
    ListNode* rt = nullptr;
    ListNode* temp = head;
    int pos = 1;

    while(temp != nullptr){
        if(pos == left - 1){
            ltprev = temp;
            lt = temp->next;
        }
        if(pos == right){
            rt = temp;
            rtnext = temp->next;
            break;             
        }
        temp = temp->next;
        pos++;
    }

    ListNode* i = lt;
    ListNode* j = lt->next;
    while(j != rtnext){
        ListNode* t = j->next;
        j->next = i;
        i = j;
        j = t;
    }

    if(ltprev) ltprev->next = rt;  
    else head = rt;                
    lt->next = rtnext;             
    return head;
    }
};