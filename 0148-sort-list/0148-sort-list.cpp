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
    ListNode* sortList(ListNode* head) {
    /*
        *****MAI MADARCHOOD HU !!!!!!!!*****
        priority_queue<int> p ;
        stack<int> st;
        ListNode * temp = head;
        while(temp){
            p.push(temp->val);
            temp = temp->next;
        }
        while(!p.empty()){
            st.push(p.top());
            p.pop();
        }
        ListNode * t = head;
        while(t){
            t->val = st.top();
            st.pop();
            t = t->next;
        }
        return head;
    */
        vector<int> lis ;
        ListNode * temp = head;
        ListNode * t = head;
        while(temp){
            lis.push_back(temp->val);
            temp = temp->next;
        }
        sort(lis.begin(),lis.end());
        int i = 0;
        while(t){
            t->val = lis[i];
            i++;
            t = t->next;
        }
        return head;
    }
};