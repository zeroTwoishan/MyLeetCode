class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        int n = s.size();
        st.reserve(n); 
        for(auto& c : s){
            if((c == '(') ||
              (c == '{') || 
              (c == '[')) st.push_back(c);
            else if(!st.empty() &&
                    ((st.back() == '[' && c == ']') ||
                    (st.back() == '{' && c == '}') ||
                    (st.back() == '(' && c == ')')) ) st.pop_back();
            else return false;
        }
        return st.empty();
    }
};
/*
class Solution {
public:
    bool isValid(string s) {
        int lenght = s.size();
        if(lenght % 2 != 0) return false;
        else{
            string open;
            for(int i = 0;i<lenght;i++){
                char ch=s[i];
                if(ch=='(' || ch == '{' || ch == '[') open.push_back(ch);
                else{
                    if(open.size() == 0) return false;
                    if((open.back()=='(' && ch==')') ||(open.back()=='{' && ch=='}')||
                    (open.back()=='[' && ch==']') ) {
                        open.pop_back();
                    }
                    else return false;
                    
                }
            }
            if(open.size()!= 0)return false;
            return true;           
        }
    }
};
*/