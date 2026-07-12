class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        unsigned int num = n;  
        
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (num & 1);
            num >>= 1;
        }
        
        return result;
    }
};
