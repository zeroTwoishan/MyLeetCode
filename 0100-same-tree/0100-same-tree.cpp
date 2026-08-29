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
    void traverse(TreeNode* root, vector<int>& tree){
        if(root == nullptr){
            tree.push_back(INT_MIN);
            return;
        }

        traverse(root->left,tree);
        traverse(root->right,tree);
        tree.push_back(root->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> tree1,tree2;
        traverse(p,tree1);

        tree2.reserve(tree1.size());

        traverse(q,tree2);

        return (tree1 == tree2);
    }
};
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val 
            && isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
    }
};