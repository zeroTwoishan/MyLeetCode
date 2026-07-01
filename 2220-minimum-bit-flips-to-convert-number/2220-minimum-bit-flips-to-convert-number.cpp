class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*if(start == goal) return 0;
        int count = 0;
        for(int i = 0; i < 32; i++) {
            int bitA = (start >> i) & 1;  
            int bitB = (goal >> i) & 1;
            if(bitA != bitB) count++;
        }
        return count;*/
        return __builtin_popcount(start ^ goal);
    }
};