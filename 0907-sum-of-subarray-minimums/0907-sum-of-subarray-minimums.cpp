class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        vector<int> st;
        st.reserve(n);

        // left[i] = distance to previous strictly-smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
            left[i] = st.empty() ? (i + 1) : (i - st.back());
            st.push_back(i);
        }

        st.clear();
        // right[i] = distance to next smaller-or-equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.back()] > arr[i]) st.pop_back();
            right[i] = st.empty() ? (n - i) : (st.back() - i);
            st.push_back(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum = (sum + (long long)arr[i] * left[i] % MOD * right[i]) % MOD;

        return (int)sum;
    }
};