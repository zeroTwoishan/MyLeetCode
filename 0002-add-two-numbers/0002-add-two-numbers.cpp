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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * t1 = l1;
        ListNode * t2 = l2;
        ListNode * newhead = nullptr;
        ListNode * mover;
        int c = 0;
        while(t1 != nullptr || t2 != nullptr || c){
            int sum = c;
            if(t1 != nullptr){
                sum += t1->val;
                t1 = t1->next;
            }
            if(t2 != nullptr){
                sum += t2->val;
                t2 = t2->next;
            }
            c =  sum / 10;
            sum = sum % 10;
            ListNode * Node = new ListNode(sum);
            if(newhead == nullptr){
                newhead = Node;
                mover = newhead;
            }
            else{
            mover->next = Node;
            mover = mover->next;
            }
        }
        return newhead;
    }
};