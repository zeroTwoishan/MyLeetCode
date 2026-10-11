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
    void traverse(TreeNode* root, vector<TreeNode*>& store) {
        if (!root) return;
        store.push_back(root);
        traverse(root->left, store);
        traverse(root->right, store);
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> store;
        traverse(root, store);
        int n = store.size();
        for (int i = 0; i < n - 1; i++) {
            store[i]->left = nullptr;
            store[i]->right = store[i + 1];
        }
    }
};