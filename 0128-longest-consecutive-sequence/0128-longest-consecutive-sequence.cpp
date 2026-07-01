class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxlen =1;
        int n = nums.size();
        /*
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            else if(1==nums[i]-nums[i-1]) len++;
            else len=1;
            maxlen=max(maxlen,len);
        }
        */
        unordered_set<int> s;
        for(int i = 0 ; i<n;i++){
            s.insert(nums[i]);
        }
        for(auto it : s){
            if(s.find(it-1)==s.end()){
                int len=1;
                int x=it;
                while(s.find(x+1)!=s.end()){
                    len++;
                    x=x+1;
                    maxlen=max(maxlen,len);
                }
            }
        }
        
        return maxlen;
    }
};