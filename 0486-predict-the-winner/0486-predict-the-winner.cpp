class Solution {
public:
    unordered_map<long long, int> memo;

    int winner(int* base, int left, int right){
        if (left == right) return base[left];
        long long key = (long long)left * 100000 + right;  // encode (left,right) as one key
        if (memo.count(key)) return memo[key];

        int pickLeft  = base[left]  - winner(base, left + 1, right);
        int pickRight = base[right] - winner(base, left, right - 1);
        return memo[key] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return winner(nums.data(), 0, (int)nums.size() - 1) >= 0;
    }
};