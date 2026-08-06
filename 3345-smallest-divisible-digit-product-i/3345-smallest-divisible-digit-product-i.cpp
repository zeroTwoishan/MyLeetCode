class Solution {
public:
    int smallestNumber(int n, int t){
        while(true){
            int num = n;
            int pro = 1;
            while(num > 0){
                int r = num % 10;
                if(r == 0) return n;
                pro *= r;
                num /= 10;
            }
            if(pro % t == 0) return n;
            n++;
        }
    }
};