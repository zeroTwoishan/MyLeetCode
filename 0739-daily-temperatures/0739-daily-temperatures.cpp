class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> st;
        st.reserve(n);  

        for(int i = 0; i < n; i++){
            while(!st.empty() && temp[i] > temp[st.back()]){
                temp[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        while(!st.empty()){
            temp[st.back()] = 0;
            st.pop_back();
        }
        return temp;
/*
        vector<int> ans;
        for(int i = 0;i < n; i++){
            int j = i;
            while(j < n){
                if(temp[j] > temp[i]){
                    ans.push_back(j - i);
                    break;
                }
                j++;
            }
            if(j >= n) ans.push_back(0);
        return ans;
*/
    }
};