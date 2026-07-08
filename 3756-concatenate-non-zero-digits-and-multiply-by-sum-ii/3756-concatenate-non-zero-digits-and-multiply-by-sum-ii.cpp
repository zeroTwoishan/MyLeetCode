class Solution {
public:
    long long m = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= m;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % m;
            base = (base * base) % m;
            exp >>= 1;
        }
        return result;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> prefixSum(n + 1, 0), noUpto(n + 1, 0);
        vector<int> nonZero(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            noUpto[i + 1]    = noUpto[i];
            nonZero[i + 1]   = nonZero[i];
            if (s[i] != '0') {
                int d = s[i] - '0';
                prefixSum[i + 1] = (prefixSum[i] + d) % m;
                noUpto[i + 1]    = ((noUpto[i] * 10) % m + d) % m;
                nonZero[i + 1]   = nonZero[i] + 1;
            }
        }

        vector<int> ans;
        for (auto& v : queries) {
            int l = v[0], r = v[1]; 

            long long no  = ((noUpto[r+1] - (noUpto[l] * power(10, nonZero[r+1]-nonZero[l])) % m) % m + m) % m;
            long long sum = ((prefixSum[r+1] - prefixSum[l]) % m + m) % m;
            ans.push_back((no * sum) % m);
        }
        return ans;
    }
};