class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);  
       string ans1;
       vector<string> temp;                 
       while (ss >> ans1) {
        temp.push_back(ans1);
    }
    string ans;
    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        ans+= *it;
        if(it != temp.rend()-1){
        ans+=" ";
        }
    }
        return ans;
    }
};