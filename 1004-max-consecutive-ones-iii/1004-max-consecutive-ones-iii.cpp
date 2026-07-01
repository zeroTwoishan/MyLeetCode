class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int noOfZero = 0;
        int maxx = 0;          
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == 0) noOfZero++;
            while(noOfZero > k){         
                if(nums[i] == 0) noOfZero--;
                i++;
            }
            maxx = max(maxx, j - i + 1); 
        }
        return maxx;
    }
};