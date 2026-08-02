class Solution {
public:
    int winner(int* left, int* right){
        if (left == right) return *left;
        int pickLeft  = *left  - winner(left + 1, right);
        int pickRight = *right - winner(left, right - 1);
        return max(pickLeft, pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        return winner(nums.data(), nums.data() + nums.size() - 1) >= 0;
    }
};