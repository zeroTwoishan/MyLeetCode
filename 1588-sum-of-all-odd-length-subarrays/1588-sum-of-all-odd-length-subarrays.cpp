class Solution {
public:
/*
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int summ = arr[i];
            sum += arr[i];
            for(int j = (i + 2); j < n; j += 2){
                summ += arr[j] + arr[j - 1];
                sum += summ;
            }
        }
        return sum;
    }
*/
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        // For each index i, count how many ODD-length subarrays
        // contain arr[i], then add arr[i] * count to the answer.
        // (Contribution technique: instead of summing subarrays,
        // sum each element's total contribution across all subarrays.)
        for (int i = 0; i < n; i++) {

            // end  = number of subarrays that END at index i
            //         (start varies 0..i, end fixed at i)        => i+1 choices
            // start = number of subarrays that START at index i
            //         (start fixed at i, end varies i..n-1)      => n-i choices
            // total = left * right = TOTAL subarrays (odd + even length) containing i
            //         (pairing every "ends at i" prefix with every "starts at i" suffix
            //          gives every subarray that passes through i, counted once each)
            int total = (n - i) * (i + 1);

            // Key fact: among `total` subarrays containing index i,
            // odd-length and even-length subarrays split as evenly as possible:
            //   - if total is odd  -> ceil(total/2) are odd-length
            //   - if total is even -> total/2 are odd-length
            if (total % 2 != 0) {
                // odd total -> ceil(total/2) = (total+1)/2, done via bit-shift
                sum += ((total + 1) >> 1) * arr[i];
            } else {
                // even total -> exactly total/2 odd-length subarrays
                sum += (total >> 1) * arr[i];
            }
        }

        return sum;
    }
};