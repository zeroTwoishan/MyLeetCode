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
    ListNode * reverse(ListNode * head){
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * newhead = reverse(slow->next);
        ListNode * tt = newhead;
        ListNode * temp = head;
        int maxx = INT_MIN;
        while(tt != nullptr){
            maxx = max(maxx,(temp->val + tt->val));
            temp = temp->next;
            tt = tt->next;            
        }
        reverse(newhead);
        return maxx;
    }
};