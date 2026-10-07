class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> store;
        int score = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                store.push_back(score);
                score = 0;
            }
            else if(s[i] == ')'){
                score = store.back() + max(2 * score , 1);
                store.pop_back();
            }
        }
        
        return score;
    }
};