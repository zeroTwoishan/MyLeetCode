class Solution {
public:
    long long sumMin(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>st;
        vector<int> left(n),right(n);
        st.reserve(n);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < nums[st.back()]) st.pop_back();
            left[i] = (st.empty()) ? (i + 1) : (i - st.back());
            st.push_back(i);
        }
        st.clear();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] <= nums[st.back()]) st.pop_back();
            right[i] = (st.empty()) ? (n - i) : (st.back() - i);
            st.push_back(i);
        }
        for(int i = 0; i < n; i++){
            sum += (long long)left[i] * right[i] * nums[i];
        }
        return sum;
    }
    long long sumMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);  
    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.back()] < nums[i]) {
            right[st.back()] = i - st.back();
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {           
        right[st.back()] = n - st.back();
        st.pop_back();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.back()] <= nums[i]) {
            left[st.back()] = st.back() - i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {                 
        left[st.back()] = st.back() + 1;
        st.pop_back();
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long long)left[i] * right[i] * nums[i];
    return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};