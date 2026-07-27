class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n1 = INT_MIN;
        int n2 = INT_MIN;
        int n3 = INT_MIN;
        int s1 = INT_MAX, s2 = INT_MAX;

        for(auto& num : nums){
            if(num > n1){
                n3 = n2;
                n2 = n1;
                n1 = num;
            }
            else if(num > n2){
                n3 = n2;
                n2 = num;
            }
            else if(num > n3) n3 = num;

            if (num < s1) {
                s2 = s1;
                s1 = num;
            } else if (num < s2) {
                s2 = num;
            }
        }
        return max(n1 * n2 * n3, s1 * s2 * n1);
    }
};