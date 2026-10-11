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
    TreeNode* tree(vector<int>& preorder, int prstart, int prstop, vector<int>& inorder,
    int instart, int instop, unordered_map<int,int>& hash){
        if(prstart > prstop || instart > instop) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[prstart]);

        int posRoot = hash[root->val];
        int numsLeft = posRoot - instart;

        root->left = tree(preorder, prstart + 1, prstart + numsLeft, inorder, instart, posRoot - 1, hash);

        root->right = tree(preorder, prstart + numsLeft + 1, prstop, inorder, posRoot + 1, instop, hash);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hash;
        for(int i = 0; i < inorder.size(); i++){
            hash[inorder[i]] = i;
        }
        TreeNode* root = tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, hash);
        
        return root;
    }
};