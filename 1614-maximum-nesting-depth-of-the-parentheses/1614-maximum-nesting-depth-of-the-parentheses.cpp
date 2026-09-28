class Solution {
public:
    int maxDepth(string s) {
        int brackets = 0;
        int nesting = 0;
        for(auto c : s){
            if(c == ')'){
                nesting = max(nesting,brackets);
                brackets--;
            }
            if(c =='('){
                brackets++;
            }
        }
        return nesting;
    }
};