class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int i = 0, j = n - 1;
        int val = 1;
        while(i < j){
            ans[i] = val;
            ans[j] = -val;
            val++;
            i++;
            j--;
        }
        return ans;
    }
};