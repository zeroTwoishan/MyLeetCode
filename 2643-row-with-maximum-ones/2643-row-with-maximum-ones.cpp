class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int bestRow = 0, bestCount = 0;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int x : mat[i]) cnt += x;
            if (cnt > bestCount) {
                bestCount = cnt;
                bestRow = i;
            }
        }
        return {bestRow, bestCount};
    }
};