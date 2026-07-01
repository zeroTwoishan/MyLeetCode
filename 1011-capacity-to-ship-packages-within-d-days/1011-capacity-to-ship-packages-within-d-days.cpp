class Solution {
public:
    int funtion(vector<int>& weights, int cap) {
        int day = 1;
        int sum = 0;
        for (int j = 0; j < weights.size(); j++) {
            if (sum + weights[j] > cap) {
                day++;
                sum = 0;
            }
            sum += weights[j];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int day = funtion(weights, mid);
            if (day <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};