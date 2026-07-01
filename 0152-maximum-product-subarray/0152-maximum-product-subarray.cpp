class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;
        int leftP = 1;
        int rightP = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(leftP == 0) leftP = 1;
            if(rightP == 0) rightP = 1;
            leftP *= nums[i];
            rightP *= nums[n-i-1];
            maxP=max(maxP,leftP);
            maxP=max(maxP,rightP);
        }
        return maxP;
    }
};