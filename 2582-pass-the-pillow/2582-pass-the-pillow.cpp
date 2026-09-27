class Solution {
public:
    int passThePillow(int n, int time) {
        int period = 2 * (n - 1);

        time = time % period;

        return time < n ? time + 1 : period - time + 1;
    }
};