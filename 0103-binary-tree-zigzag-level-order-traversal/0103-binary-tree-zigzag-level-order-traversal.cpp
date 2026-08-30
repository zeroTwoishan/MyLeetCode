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
    void dfs(TreeNode* node, int depth, vector<vector<int>>& ans) {
        if (node == nullptr) return;
        
        if (depth == ans.size()) {
            ans.push_back({});
        }

        ans[depth].push_back(node->val);

        dfs(node->left, depth + 1, ans);
        dfs(node->right, depth + 1, ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        for(int i = 0; i < ans.size(); i++){
            if(i % 2 != 0) reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};