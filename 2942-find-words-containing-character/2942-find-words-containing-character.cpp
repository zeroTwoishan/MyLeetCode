class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        ans.reserve(n);
        for(int i = 0; i < n; i++){
            for(auto& w : words[i]){
                if(w == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};