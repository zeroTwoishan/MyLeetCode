class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> present(upper + 1, false);

        for (int num : nums) {
            if (num >= lower && num <= upper) {
                present[num] = true;
            }
        }

        vector<vector<int>> ans;

        int i = lower;

        while (i <= upper) {
            if (present[i]) {
                i++;
                continue;
            }

            int start = i;

            while (i <= upper && !present[i]) {
                i++;
            }

            ans.push_back({start, i - 1});
        }

        return ans;
    }
};