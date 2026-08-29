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
    int height(TreeNode* root,int& maxx){
        if(root == nullptr) return 0;

        int left = height(root->left,maxx);
        int right = height(root->right,maxx);

        maxx = max(maxx,left + right);

        return 1 + max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx = -1;

        height(root,maxx);

        return maxx ;
    }
};

/*
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left,right);
    }
    int maxx = -1;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        int leftdia = diameterOfBinaryTree(root->left);
        int rightdia = diameterOfBinaryTree(root->right);

        maxx = max(left + right,maxx);
        return maxx ;
    }
};
*/