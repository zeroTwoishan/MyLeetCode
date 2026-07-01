class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * nt = head;
        ListNode * last = head;
        for(int i = 0; i < n; i++){
            last = last->next;
        }

        if(last == nullptr){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(last->next != nullptr){
            nt = nt->next;
            last = last->next;
        }
        ListNode* toDelete = nt->next;
        nt->next = nt->next->next;
        delete toDelete;
        return head;
    }
};