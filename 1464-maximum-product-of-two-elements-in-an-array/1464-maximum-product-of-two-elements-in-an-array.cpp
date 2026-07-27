class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n1 = INT_MIN;
        int n2 = INT_MIN;

        for(auto& num : nums){
            if(num > n1){
                n2 = n1;
                n1 = num;
            }
            else if(num > n2) n2 = num;
        }
        return ((n1 - 1) * (n2 - 1));
    }
};