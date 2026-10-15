class Solution {
public:
    void traverse(TreeNode* root, vector<string>& ans, string path) {
        path += to_string(root->val);

        if (!root->left && !root->right) {   // leaf
            ans.push_back(path);
            return;
        }

        path += "->";
        if (root->left)  traverse(root->left, ans, path);
        if (root->right) traverse(root->right, ans, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root) traverse(root, ans, "");
        return ans;
    }
};