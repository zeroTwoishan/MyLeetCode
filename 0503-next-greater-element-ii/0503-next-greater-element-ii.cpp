class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    vector<int> st;
    st.reserve(n);
    for (int i = 0; i < 2 * n; i++) {
        int j = i % n;
        while (!st.empty() && nums[j] > nums[st.back()]) {
            ans[st.back()] = nums[j];
            st.pop_back();
        }
        st.push_back(j);
    }
    return ans;
}
};