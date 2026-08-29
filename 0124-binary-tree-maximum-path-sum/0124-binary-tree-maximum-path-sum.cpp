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
    int maxSum(TreeNode* root, int& maxx){
        if(root == nullptr) return 0;

        int left = max(maxSum(root->left, maxx),0);
        int right = max(maxSum(root->right, maxx),0);

        maxx = max(left + right + root->val, maxx);

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN;

        maxSum(root,maxx);

        return maxx;
    }
};