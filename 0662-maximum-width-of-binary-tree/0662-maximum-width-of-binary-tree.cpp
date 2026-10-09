/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        unsigned long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            unsigned long long base = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < n; i++) {
                unsigned long long id = q.front().second - base;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = id;
                if (i == n - 1) last = id;

                if (node->left)  q.push({node->left,  2 * id + 1});
                if (node->right) q.push({node->right, 2 * id + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};