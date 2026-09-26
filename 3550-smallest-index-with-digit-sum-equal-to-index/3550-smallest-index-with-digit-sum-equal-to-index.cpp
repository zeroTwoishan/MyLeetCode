class Solution {
public:
    bool check(int i, int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n /= 10;
        }
        return i == sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(check(i,nums[i])) return i;
        }
        return -1;
    }
};