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
    pair<int,int> function(TreeNode* root,int& count,vector<int>& temp){
        if(root == nullptr){ 
            return {0,0};
        }
        auto [leftSum, leftCount] = function(root->left,count,temp);
        auto [rightSum, rightCount] = function(root->right,count,temp);

        int sum = leftSum + rightSum + root->val;
        int nodes = leftCount + rightCount + 1;
        if(root->val == (sum / nodes)) count++;

        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        vector<int> temp;
        int count = 0;
        function(root,count,temp);
        return count;
    }
};