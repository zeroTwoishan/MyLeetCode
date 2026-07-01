class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> last(26,-1),first(26,-1);
        int ans = 0;
        for(int i = 0; i<word.size();i++){
            if(islower(word[i])){
                last[word[i] -'a'] =i;
            }
            else{
                if(isupper(word[i])){
                    if(first[word[i] - 'A']==-1){
                        first[word[i] - 'A'] = i;
                    }
                }
            }
        }
        for(int i = 0; i<26;i++){
            if(last[i]!=-1 && first[i]!=-1 && last[i]<first[i]) ans++;
        }
        return ans;
    }
};