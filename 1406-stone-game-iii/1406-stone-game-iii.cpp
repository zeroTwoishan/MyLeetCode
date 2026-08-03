/*
class Solution {
public:
    int mpp;
    int game(vector<int>& value, int i){
        int n = value.size();
        if(i >= n) return 0;

        if(mpp[i] != INT_MIN) return mpp[i];

        int pickOne = value[i] - game(value, i + 1);
        int pickTwo = INT_MIN;
        if(n - i > 1) pickTwo = value[i] + value[i + 1] - game(value, i + 2);
        int pickThree = INT_MIN;
        if(n - i > 2) pickThree = value[i] + value[i + 1] + value[i + 2] - game(value, i + 3);
        mpp[i] = max({pickOne, pickTwo, pickThree});

        return mpp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        mpp.assign(stoneValue.size(), INT_MIN);
        int result = game(stoneValue, 0);
        if(result > 0) return "Alice";
        else if(result == 0) return "Tie";
        else return "Bob";
    }
};
*/
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN;
            int sum = 0;
            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                best = max(best, sum - dp[i + k + 1]);
            }
            dp[i] = best;
        }

        if (dp[0] > 0) return "Alice";
        else if (dp[0] == 0) return "Tie";
        else return "Bob";
    }
};