class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int b=0,c=0;
        int d=x;
        while(x>0){
            c=x%10;
            x=x/10;
            if(b>INT_MAX/10||b==INT_MAX/10 && c>7) return false;
            b=10*b+c;
        }
        return (b==d) ;   
    }
};