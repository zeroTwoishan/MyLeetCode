class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int freq[51] = {0};
        for(auto& i : nums){
            freq[i]++;
        }
        int XOr = 0;
        for(int i = 0; i < 51; i++){
            if(freq[i] > 1) XOr ^= i;
        }
        return XOr;
    }
};