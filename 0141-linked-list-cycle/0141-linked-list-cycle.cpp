/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       /*
       unordered_set<ListNode * > s;
       ListNode * temp = head;
        while(temp != nullptr){
            if(s.count(temp)) return true;
            s.insert(temp);
            temp = temp->next;
        }
        return false;
        */
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};