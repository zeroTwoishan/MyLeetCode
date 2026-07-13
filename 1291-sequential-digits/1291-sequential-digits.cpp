class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string no = "123456789";
        int ll = 0,hh = 0;
        int n = low;
        while(n > 0){
            ll++;
            n /= 10;
        }
        n = high;
        while(n > 0){
            hh++;
            n /= 10;
        }
        vector<int> ans;
        for(int len = ll; len <= hh; len++){
            for(int i = 0; i < (10 - len); i++){
            n = stoi(no.substr(i,len));
            if(n <= high && n >= low) ans.push_back(n);
            }
        }
        return ans;
    }
};