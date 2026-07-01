class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        if (head->val >= 5) {
            head = new ListNode(0, head);
        }

        ListNode* temp = head;

        while (temp != nullptr) {

            temp->val = (temp->val * 2) % 10;

            if (temp->next != nullptr && temp->next->val >= 5) {
                temp->val += 1;
            }

            temp = temp->next;
        }

        return head;
    }
};