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
        stack<int> s1,s2;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1 != nullptr || t2 != nullptr){
            if(t1 != nullptr){
                s1.push(t1->val);
                t1 = t1->next;
            }
            if(t2 != nullptr){
                s2.push(t2->val);
                t2 = t2->next;
            }
        }
        ListNode* ans = nullptr;
        int c = 0;
        while(!s1.empty() || !s2.empty() || c){
            int sum = c;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            c = sum / 10;
            sum = sum % 10 ;
            ListNode* Node = new ListNode(sum);
            Node->next = ans;
            ans = Node;
        }
        return ans;
    }
};