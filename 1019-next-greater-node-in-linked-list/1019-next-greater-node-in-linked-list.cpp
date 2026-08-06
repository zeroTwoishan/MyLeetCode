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
    int lenght(ListNode* head){
        int len = 0;
        while(head != nullptr){
            len++;
            head = head->next;
        }
        return len;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next == nullptr) return {0};
        int len = lenght(head);
        vector<pair<int,int>> st;
        st.reserve(len);
        vector<int> ans(len,0);
        int index = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            while(!st.empty() && temp-> val > st.back().first){
                ans[st.back().second] = temp-> val;
                st.pop_back();
            }
            st.push_back({temp->val,index});
            index++;
            temp = temp->next;
        }
        return ans;
    }
};