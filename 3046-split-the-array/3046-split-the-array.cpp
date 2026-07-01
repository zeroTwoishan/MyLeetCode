class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int freq[101] = {0};
        for (int x : nums) {
            if (++freq[x] > 2) return false;
        }
        return true;
    }
};