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

class Solution {
public:
    void traverse(TreeNode* root, vector<string>& ans, string temp) {
        if (root == nullptr) return;
        temp.push_back('0' + root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
            return;
        }
        traverse(root->left, ans, temp);
        traverse(root->right, ans, temp);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> sum;
        string temp;
        traverse(root,sum,temp);
        int ans = 0;
        for(auto c : sum){
            ans += stoi(c);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int dfs(TreeNode* root, int cur) {
        if (root == nullptr) return 0;
        cur = cur * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return cur;
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};