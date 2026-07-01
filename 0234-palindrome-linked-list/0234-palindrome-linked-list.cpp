class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        for(ListNode* c = head; c != nullptr; c = c->next)
            vals.push_back(c->val);

        int i = 0, j = vals.size() - 1;
        while(i < j){
            if(vals[i] != vals[j]) return false;
            i++; j--;
        }
        return true;
    }
};