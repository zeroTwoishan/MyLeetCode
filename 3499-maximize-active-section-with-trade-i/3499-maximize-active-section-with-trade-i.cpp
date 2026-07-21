class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxx = 0;
        int oneCount = count(s.begin(),s.end(), '1');
        vector<int> zero;
        zero.reserve(s.size());
        int i = 0;
        while(i < s.size()){
            if(s[i] == '0'){
                int start = i;
                while(s[i] == '0') i++;
                zero.push_back(i - start);
            }
            else i++;
        }
        i = 0;
        int j = 1;
        while(j < zero.size()){
            maxx = max(maxx,zero[i] + zero[j]);
            i++;
            j++;
        }
        return maxx + oneCount;
    }
};