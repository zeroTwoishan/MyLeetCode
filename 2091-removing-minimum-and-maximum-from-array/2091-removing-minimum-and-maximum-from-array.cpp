class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1 = 0;
        int idx2 = 0;
        int maxx = nums[0];
        int minn = nums[0];
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > maxx){
                maxx = nums[i];
                idx1 = i;
            }
            if(nums[i] < minn){
                minn = nums[i];
                idx2 = i;
            }
        }
        int front = max(idx1,idx2) + 1;
        int back = max(n - idx1, n - idx2);
        int both = min(idx1,idx2) + min(n - idx1, n - idx2) + 1;

        return min(front,min(back,both));
    }
};