class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(auto& num : nums){
            minn = min(minn,num);
            maxx = max(maxx,num);
        }
        for(int i = minn; i >=1; i--){
            if(((minn % i) == 0) && ((maxx % i) == 0)) return i;
        }
        return 1;
    }
};