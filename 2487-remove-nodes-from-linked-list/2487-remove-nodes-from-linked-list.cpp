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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        int maxVal = curr->val;
        while (curr->next) {
            if (curr->next->val < maxVal) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxVal = curr->val;
            }
        }
        return reverse(head);
    }
};

/*
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head->next == nullptr) return head;
        vector<ListNode*> st;
        ListNode* temp = head;
        while(temp != nullptr){
            while(!st.empty() && temp->val > st.back()->val){
                st.back()->val = -1;
                st.pop_back();
            }
            st.push_back(temp);
            temp = temp->next;
        }
        while(head != nullptr && head->val == -1) head = head->next;
        temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->next->val == -1) temp->next = temp->next->next;
            else temp = temp->next;
        }
        return head;
    }
};
*/