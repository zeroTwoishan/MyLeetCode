class Solution {
public:
    long long Time(int x,vector<int>&arr){
        long long timee = 0;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] % x == 0) timee+=(arr[i]/x);
            else timee+=((arr[i]/x)+1);
        }
        return timee;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxE = *max_element(piles.begin(),piles.end());
        int low = 1,high = maxE;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            long long tim = Time(mid,piles);
            if(tim<=h){
                ans = mid;
                high = mid-1;
            }
            else if (tim>h) low = mid+1;
        }
        return ans;
    }
};