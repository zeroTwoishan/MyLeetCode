class Solution {
public:
    static int getDigitsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    static bool logic(int num1, int num2) {
        int dSum1 = getDigitsum(num1);
        int dSum2 = getDigitsum(num2);

        if (dSum1 != dSum2)
            return dSum1 < dSum2;

        return num1 < num2;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> expected = nums;
        sort(expected.begin(), expected.end(), logic);

        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == expected[i])
                continue;

            int j = mpp[expected[i]];
            mpp[nums[i]] = j;     
            mpp[expected[i]] = i;
            swap(nums[i], nums[j]);
            swaps++;
        }
        return swaps;
    }
};