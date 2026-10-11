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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> nodes;
        int ans = 0;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* node = nodes.front();
            nodes.pop();
            ans++;
            if(node->left) nodes.push(node->left);
            if(node->right) nodes.push(node->right); 
        }
        return ans;
    }
};
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = 0, rh = 0;
        TreeNode* l = root;
        TreeNode* r = root;

        while (l) { lh++; l = l->left; }
        while (r) { rh++; r = r->right; }

        if (lh == rh) return (1 << lh) - 1;   // perfect tree

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};