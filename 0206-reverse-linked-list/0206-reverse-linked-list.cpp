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
    ListNode* reverseList(ListNode* head) {
        /*vector<int> temp ;
        while(head != nullptr){
            temp.push_back(head->val);
            head = head->next;
        }
        if(temp.size() == 0) return nullptr;
        ListNode * newhead = new ListNode(temp[temp.size() - 1]);
        ListNode * mover = newhead;
        for(int i = temp.size() - 2; i>=0; i--){
            ListNode * t = new ListNode(temp[i]);
            mover->next = t;
            mover = mover->next;
        }
    return newhead;*/
    ListNode * p = nullptr;
    ListNode * c = head;
    while(c!=nullptr){
        ListNode * n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;   
    }
};