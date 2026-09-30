class Solution {
public:
    int closestTarget(vector<string>& words, string target, int j) {
        int n = words.size();
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int st = abs(i - j);
                int cir = n - st;

                ans = min(ans,min(st,cir));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};