class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());
        for(auto& c : tokens){
            if(c != "+" && c != "-" && c != "*" && c != "/") st.push_back(stoi(c));
            else{
                int second = st.back();
                st.pop_back();
                int first = st.back();
                st.pop_back();
                if(c == "+") st.push_back(first + second);
                else if(c == "-") st.push_back(first - second);
                else if(c == "*") st.push_back(first * second);
                else st.push_back(first / second);
            }
        }
        return st.back();
    }
};