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
    void traverse(TreeNode* root,vector<int>& tree,bool leftFirst){
        if(root == nullptr){
            tree.push_back(INT_MIN);
            return;
        }

        if(leftFirst){
            traverse(root->left,tree,leftFirst);
            traverse(root->right,tree,leftFirst);
        }
        else{
            traverse(root->right,tree,leftFirst);
            traverse(root->left,tree,leftFirst);
        }
            tree.push_back(root->val);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> left, right;
        traverse(root->left,left,true);
        traverse(root->right,right,false);

        return (left == right);
    }
};