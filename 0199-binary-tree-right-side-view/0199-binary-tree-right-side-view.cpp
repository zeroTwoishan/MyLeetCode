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
    void traverse(TreeNode* root, int row, int col, unordered_map<int,vector<int>>& mpp){
        if(root == nullptr){
            return;
        }

        mpp[row].push_back(root->val);

        traverse(root->left, row + 1, col - 1,mpp);
        traverse(root->right, row + 1, col + 1,mpp);
    }
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,vector<int>> mpp;
        traverse(root,0,0,mpp);  
        int rows = mpp.size(); 
        vector<int> ans;
        ans.reserve(rows);
        for(int i = 0; i < rows; i++){
            ans.push_back(mpp[i].back());
        }         
        return ans;
    }
};
*/

class Solution {
public:
    void traverse(TreeNode* root, int row, vector<int>& ans) {
        if (!root) return;
        if (row == ans.size()) ans.push_back(root->val);
        else ans[row] = root->val;   // later (more rightward) node overwrites
        traverse(root->left, row + 1, ans);
        traverse(root->right, row + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, 0, ans);
        return ans;
    }
};