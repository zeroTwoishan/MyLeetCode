class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> indexOf;
        indexOf.reserve(nums1.size());
        for(int i = 0; i < nums1.size(); i++) indexOf[nums1[i]] = i;

        vector<int> st;
        st.reserve(nums2.size());
        vector<int> ans(nums1.size(), -1);

        for(int num : nums2){
            while(!st.empty() && num > st.back()){
                auto it = indexOf.find(st.back());
                if(it != indexOf.end()) ans[it->second] = num;
                st.pop_back();
            }
            st.push_back(num);
        }
        return ans;
    }
};