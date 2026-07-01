class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a,b;
        vector<int> c;
        while(n>0){
            a=n%2;
            n=n/2;
            c.push_back(a);
            
        }
        for (auto it = c.begin(); it != c.end() - 1; ++it){
            if (*it == *(it + 1)) return false;
        }
        return true;

    }
};