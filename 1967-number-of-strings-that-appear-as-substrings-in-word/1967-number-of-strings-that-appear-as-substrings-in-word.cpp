class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count  = 0;
        int n = patterns.size();
        int w = word.size();
        for(int i = 0; i < n; i++){
            if(patterns[i].size() > w) continue;
            if(word.contains(patterns[i])) count++;
        }
        return count;
    }
};