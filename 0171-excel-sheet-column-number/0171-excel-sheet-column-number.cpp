class Solution {
public:
    int titleToNumber(string columnTitle) {
        double ans=0;
        reverse(columnTitle.begin(),columnTitle.end());
        int n = columnTitle.size();
        for( int  i = 0 ; i < n ; i++){
            double p = pow(26,i);
            ans += (int(columnTitle[i])-64)*p;
        }
        return (int)ans;
    }
};