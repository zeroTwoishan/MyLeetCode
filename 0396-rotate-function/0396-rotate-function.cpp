class Solution {
public:
/*   Brute Force

    int F(vector<int>& nums,int k){
        vector<int>temp = nums;
        k=k%temp.size();
        if (k!=0){
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
        reverse(temp.begin(),temp.end());
        }
        int ans =0;
        int i = 0;
        while(i < temp.size()){
            ans+=temp[i]*i;
            i++;
        }
        return ans;

    }
    int maxRotateFunction(vector<int>& nums) {
        int  i = 0;
        int ans = F(nums, 0);
        while(i<nums.size()){
            ans=max(ans,F(nums,i));
            i++;
        }
        return ans;
    }
*/
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            f0+=i*nums[i];
        }
        int ans = f0;
        int f_pre=f0;
        int f_next;
        for(int i = 0;i<n;i++){
            f_next=f_pre + sum - n*nums[n-i-1];
            ans=max(f_next,ans);
            f_pre = f_next;
        }
        return ans;
    }
};