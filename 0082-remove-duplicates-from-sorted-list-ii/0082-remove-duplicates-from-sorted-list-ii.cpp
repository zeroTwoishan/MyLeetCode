class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    /*
        unordered_map<int, int> mpp;
        ListNode* temp = head;
        while (temp != nullptr) {
            mpp[temp->val]++;
            temp = temp->next;
        }
        while (head != nullptr && mpp[head->val] > 1)
            head = head->next;
        temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (mpp[temp->next->val] > 1) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    */
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            bool isDuplicate = (curr->next != nullptr && 
                                curr->val == curr->next->val);

            if (isDuplicate) {
                // skip entire group of same value
                while (curr->next != nullptr && 
                       curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;   // bypass the whole group
            } else {
                prev = prev->next;         // safe node, advance prev
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};