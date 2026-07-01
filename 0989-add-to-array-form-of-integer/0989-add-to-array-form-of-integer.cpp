class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
    /*
        int i = num.size() - 1;
        int c = 0;
        vector<int> ans;
        while(i >= 0 || k > 0 || c){
            int sum = c;
            if(i >= 0){
                sum += num[i];
                i--;
            }
            if(k > 0){
                sum += k % 10;
                k = k / 10;
            }
            c = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    */
        int i = num.size() - 1;
        while (i >= 0 && k > 0) {
            int sum = num[i] + (k % 10);
            num[i] = sum % 10;
            k = (k / 10) + (sum / 10);
            i--;
        }
        while (k > 0) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};