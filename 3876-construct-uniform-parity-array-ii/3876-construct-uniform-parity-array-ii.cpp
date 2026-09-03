class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 0;
        for(auto num : nums){
            if(num % 2 == 0) even++;
            else odd++;
        }
        if(even == n || odd == n) return true;

        int mineven = INT_MAX;
        int minodd = INT_MAX;

        for(auto num : nums){
            if(num % 2 == 0) mineven = min(mineven,num);
            else minodd = min(minodd,num);
        }

        if(minodd > mineven) return false;

        return true;
    }
};