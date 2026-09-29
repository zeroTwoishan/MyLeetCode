class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if(k < 0){
            for(int i = 0; i < n; i++){
                int sum = 0;
                int index = (i - 1 + n) % n;

                int j = 0;
                while(j < -k){
                    sum += code[index];
                    index = (index - 1 + n) % n;
                    j++;
                }

                ans[i] = sum;
            }
        }
        else{
            for(int i = 0; i < n; i++){
                int sum = 0;
                int index = (i + 1) % n;

                int j = 0;
                while(j < k){
                    sum += code[index];
                    index = (index + 1) % n;
                    j++;
                }

                ans[i] = sum;
            }
        }
        return ans;
    }
};