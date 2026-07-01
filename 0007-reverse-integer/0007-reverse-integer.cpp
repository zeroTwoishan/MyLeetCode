class Solution {
public:
    int reverse(int x) {
        int b=0,c=0;
         while(x!=0){
            c=x%10;
            x=x/10;
            if (b > INT_MAX/10|| b < INT_MIN/10)
            return 0;
            b=10*b+c;
            }
        return b;
    }
};