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
    ListNode * reverseList(ListNode * head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * curr = head;
        ListNode * prev = nullptr;
        while(curr != nullptr){
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* last = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* temp = head;
        while(last != nullptr){
            ListNode* nextt = temp->next;     
            ListNode* lastnext = last->next; 

            temp->next = last;
            last->next = nextt;

            temp = nextt;
            last = lastnext;
        }
    }
};
/*
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> list;
        ListNode * temp = head;
        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        int j = list.size() - 1;
        vector<int> finalList;
        finalList.reserve(list.size());
        for(int k = 0; k < list.size(); k++){
            if(k % 2 == 0){
                finalList.push_back(list[i]);
                i++;
            }
            else{
                finalList.push_back(list[j]);
                j--;
            }
        }
        temp = head;
        i = 0;
        while(temp != nullptr){
            temp->val = finalList[i];
            i++;
            temp = temp->next;
        }
    }
};
*/