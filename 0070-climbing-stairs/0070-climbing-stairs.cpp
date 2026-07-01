class Solution {
public:
    int C (int n , int r){
        long long ans=1;
        r = min(r,n-r);
        for(int i = 0 ; i < r;i++){
            ans *= (n - i);
            ans /= (i + 1);
        }
        return (int) ans;
    }
    int climbStairs(int n) {
        int r=0;
        int ans=0;
        int k=n/2;
        while(r<=k){
            ans = ans + C(n,r);
            n=n-1;
            r=r+1;
        }
        return ans;
    }
};