/*
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> ss;
        int n = digits.size();
        for(int i = 0; i < n; i++){
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    if(digits[k] % 2 != 0) continue;

                    int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                    ss.insert(num);
                }
            }
        }
        vector<int> ans(ss.begin(),ss.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for (int d : digits) cnt[d]++;

        vector<int> ans;
        for (int h = 1; h <= 9; h++) {          
            for (int t = 0; t <= 9; t++) {      
                for (int u = 0; u <= 8; u += 2) { 
                    int need[10] = {0};
                    need[h]++; need[t]++; need[u]++;
                    bool ok = true;
                    for (int d = 0; d < 10; d++) {
                        if (need[d] > cnt[d]) { ok = false; break; }
                    }
                    if (ok) ans.push_back(h * 100 + t * 10 + u);
                }
            }
        }
        return ans;
    }
};