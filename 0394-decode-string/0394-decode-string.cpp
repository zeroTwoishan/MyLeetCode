class Solution {
public:
    int number(vector<char>& st){
        string num = "";
        while(!st.empty() && isdigit(st.back())){
            num += st.back();
            st.pop_back();
        }
        reverse(num.begin(),num.end());
        return stoi(num);
    }
    string decodeString(string s) {
        vector<char> st;
        for(auto& c : s){
            if(c != ']') st.push_back(c);
            else{
                string inner = "";
                while(st.back() != '['){
                    inner += st.back();
                    st.pop_back();
                }
                st.pop_back();
                int n = number(st);
                reverse(inner.begin(),inner.end());
                for (int i = 0; i < n; i++) {
                    for (char ch : inner) st.push_back(ch);
                }
            }
        }
        string ans = "";
        for(auto& c : st) ans += c;
        return ans;
    }
};