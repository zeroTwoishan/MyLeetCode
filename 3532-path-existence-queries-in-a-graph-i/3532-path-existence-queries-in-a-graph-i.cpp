class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n);
        group[0] = 0;
        for (int i = 1; i < n; i++) {
            group[i] = group[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            ans.push_back(group[q[0]] == group[q[1]]);
        }
        return ans;
    }
};