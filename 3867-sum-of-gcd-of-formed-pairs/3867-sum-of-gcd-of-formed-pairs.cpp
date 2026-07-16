class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxx = nums[0];
        int n = nums.size();
        vector<int> g(n);
        for(int i = 0; i < n; i++){
            maxx = max(maxx,nums[i]);
            g[i] = gcd(maxx,nums[i]);
        }
        long long sum = 0;
        int i = 0;
        int j = n - 1;
        sort(g.begin(),g.end());
        while(i < j){
            sum += gcd(g[i],g[j]);
            i++;
            j--;
        }
        return sum;
    }
};