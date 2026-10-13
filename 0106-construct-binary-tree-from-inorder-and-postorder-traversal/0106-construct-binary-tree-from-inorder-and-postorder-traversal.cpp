/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tree(vector<int>& inorder, int instart, int inend,
                   vector<int>& postorder, int ptstart, int ptend,
                   unordered_map<int, int>& hash) {
                    if (instart > inend || ptstart > ptend) return nullptr;

        TreeNode* root = new TreeNode(postorder[ptend]);

        int rootpos = hash[postorder[ptend]];

        int numsRight = (inend - rootpos);

        root->left = tree(inorder, instart, rootpos - 1, postorder, ptstart,
                          ptend - numsRight - 1, hash);
        root->right = tree(inorder, rootpos + 1, inend, postorder,
                           ptend - numsRight, ptend - 1, hash);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
            hash[inorder[i]] = i;

        TreeNode* root = tree(inorder, 0, n - 1, postorder, 0, n - 1, hash);
        return root;
    }
};