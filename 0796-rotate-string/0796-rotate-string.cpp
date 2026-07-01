class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = s+s;
        if(s.size()!=goal.size()) return false;
        int n = s.size();
        int i=0;
        int j = n;
        while((i+n)<=temp.size()){
            if(temp.compare(i,j,goal)==0) return true;
            i++;
        }
        return false;
    }
};