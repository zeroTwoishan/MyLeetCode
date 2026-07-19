class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int firstMax = INT_MIN, secondMax = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (auto& num : nums) {
            if (num > firstMax) {
                secondMax = firstMax;
                firstMax = num;
            } else if (num > secondMax) {
                secondMax = num;
            }

            if (num < firstMin) {
                secondMin = firstMin;
                firstMin = num;
            } else if (num < secondMin) {
                secondMin = num;
            }
        }
        return (firstMax * secondMax) - (firstMin * secondMin);
    }
};