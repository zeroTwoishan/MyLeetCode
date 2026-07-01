class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> ans;
        for(auto s : strs){
            string key = s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }
        for(auto s:mpp){
            ans.push_back(s.second);
        }
        return ans;
    }
};