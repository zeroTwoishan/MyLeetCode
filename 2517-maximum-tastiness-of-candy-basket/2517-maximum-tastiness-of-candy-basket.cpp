class Solution {
public:
    bool check(vector<int>& price, int mid,int k){
        int last = price[0];
        int cnt = 1;
        for(int i = 1; i < price.size();i++){
            if((price[i] - last) >= mid){
                cnt++;
                last = price[i];
            }
        }
        return(cnt >= k);
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low = 0;
        int high = price[price.size() - 1] - price[0];
        while(low <= high){
            int mid = low + ((high - low) / 2);
            if(check(price,mid,k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};