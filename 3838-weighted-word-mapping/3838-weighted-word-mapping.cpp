class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        int n = words.size();
        ans.reserve(n);
        for(int i = 0; i < n; i++){
            int weight = 0;
            int wordSize = words[i].size();
            for(int j = 0; j < wordSize; j++){
                weight += weights[words[i][j]-'a'];
            }
            weight = weight % 26;
            ans.push_back((char)(122 - weight));
        }
        return ans;
    }
};