/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left)  { parent[node->left] = node;  q.push(node->left); }
            if (node->right) { parent[node->right] = node; q.push(node->right); }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);

        int dist = 0;
        while (!q.empty() && dist < k) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                TreeNode* nbrs[3] = {node->left, node->right,
                                     parent.count(node) ? parent[node] : nullptr};
                for (TreeNode* nxt : nbrs) {
                    if (nxt && !vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            dist++;
        }

        vector<int> ans;
        while (!q.empty()) { ans.push_back(q.front()->val); q.pop(); }
        return ans;
    }
};