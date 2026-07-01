/*
class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int oneZero = 1;   
        int zeroCnt = 0;
        int zeroIdx = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                oneZero *= nums[i];
            } else {
                zeroCnt++;
                zeroIdx = i;
            }
        }

        if(zeroCnt >= 2){
            for(int i = 0; i < n; i++) ans[i] = 0;
        } 
        else if(zeroCnt == 1){
            for(int i = 0; i < n; i++){
                ans[i] = (i == zeroIdx) ? oneZero : 0;
            }
        } 
        else {
            for(int i = 0; i < n; i++){
                ans[i] = oneZero / nums[i];
            }
        }

        return ans;
    }
};
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int leftProduct = 1;
        for(int i = 0; i < n; i++){
            ans[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return ans;
    }
};