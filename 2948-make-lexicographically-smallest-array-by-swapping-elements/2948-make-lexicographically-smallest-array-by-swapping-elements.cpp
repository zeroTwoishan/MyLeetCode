class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());

        vector<vector<int>> groups;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            vector<int> group;
            int j = i + 1;
            group.push_back(temp[j - 1]);
            while (j < n && abs(temp[j] - temp[j - 1]) <= limit) {
                group.push_back(temp[j]);
                j++;
            }
            groups.push_back(group);
            i = j;
        }

        // map each value to which group it belongs to (O(1) lookup instead of count())
        unordered_map<int, int> valueToGroup;
        for (int g = 0; g < (int)groups.size(); g++) {
            for (int v : groups[g]) {
                valueToGroup[v] = g;
            }
        }

        // pointer into each group instead of erase(begin())
        vector<int> ptr(groups.size(), 0);

        for (i = 0; i < n; i++) {
            int g = valueToGroup[nums[i]];
            nums[i] = groups[g][ptr[g]];
            ptr[g]++;
        }

        return nums;
    }
};