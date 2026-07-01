class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n=nums.size();
        /*
        Brute
        for(int i = 0;i<n;i++){
            int f=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j])
                f++;
            }
            if(f==1) return nums[i];
            }
        return -1;
        
        Better
        map<int,int> m;    
        for(int i = 0;i<n;i++){
            m[nums[i]]++;
        }  
        for(auto it:m){
            if(it.second==1) return it.first;
        } 
        return -1; 
        */
        //Best
        int Xor=0;
        for(int i = 0;i<n;i++){
            Xor=Xor^nums[i];
        }
        return Xor;
    }
};