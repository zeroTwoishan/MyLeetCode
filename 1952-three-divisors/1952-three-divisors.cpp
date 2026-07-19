class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        int i = 1;
        while((count < 4) && (i <= n)){ 
            if(n % i == 0) {
                count++;
            }
            i++;
        }
        return (count == 3);
    }
};