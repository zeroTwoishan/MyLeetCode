/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) len++;

        if (len < 3) return {-1, -1};

        vector<int> critical;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextt = curr->next;

        int index = 1;
        while (nextt != nullptr) {
            if ((curr->val < nextt->val && curr->val < prev->val) ||
                (curr->val > nextt->val && curr->val > prev->val))
                critical.push_back(index);

            prev = curr;
            curr = nextt;
            nextt = nextt->next;
            index++;
        }

        int n = critical.size();
        if (n < 2) return {-1, -1};

        int maxx = critical[n - 1] - critical[0];
        int minn = INT_MAX;
        for (int i = 0; i + 1 < n; i++)
            minn = min(minn, critical[i + 1] - critical[i]);

        return {minn, maxx};
    }
};
*/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        int first = -1, last = -1, minn = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {
                if (first == -1) {
                    first = index;
                } else {
                    minn = min(minn, index - last);
                }
                last = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (first == last) return {-1, -1};
        return {minn, last - first};
    }
};