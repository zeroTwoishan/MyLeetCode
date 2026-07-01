class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int first=0;
        int second=1;
        int third;
        int t;
        for(int i =1;i<n;i++){
            third=first+second;
            t=second;
            second=third;
            first=t;
        }
        return second;
    }
};