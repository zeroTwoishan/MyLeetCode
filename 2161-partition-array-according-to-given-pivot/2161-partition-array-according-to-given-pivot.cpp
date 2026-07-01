class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        vector<int> ans(n);
        int i = 0,j = n - 1;
        while(i < n && j >= 0){
            if(nums[i] < pivot) ans[st++] = nums[i];
            if(nums[j] > pivot) ans[end--] = nums[j];
            i++;
            j--;
        }
        while(st <= end){
            ans[st++] = pivot;
        }
        return ans;
    }
};