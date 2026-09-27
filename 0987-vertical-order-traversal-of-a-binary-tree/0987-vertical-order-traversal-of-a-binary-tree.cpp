class Solution {
public:
    void traverse(TreeNode* root, int row, int col,
                  map<int, map<int, multiset<int>>>& mpp) {
        if (root == nullptr) return;

        mpp[col][row].insert(root->val);

        traverse(root->left,  row + 1, col - 1, mpp);
        traverse(root->right, row + 1, col + 1, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
        traverse(root, 0, 0, mpp);

        vector<vector<int>> ans;
        for (auto& [col, rows] : mpp) {          // columns, left to right
            vector<int> column;
            for (auto& [row, vals] : rows) {     // rows, top to bottom
                column.insert(column.end(), vals.begin(), vals.end());  // values in sorted order
            }
            ans.push_back(column);
        }
        return ans;
    }
};