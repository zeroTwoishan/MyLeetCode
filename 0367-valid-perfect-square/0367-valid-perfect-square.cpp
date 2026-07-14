class Solution {
public:
    bool isPerfectSquare(int num) {
    int i = 1;
    while (num > 0) {
        num -= i;
        i += 2;
    }
    return num == 0;
}
    /*
    bool isPerfectSquare(int num) {
        int low = 1,high = num;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if((mid * mid) == num) return true;
            else if((mid * mid) < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    */
};