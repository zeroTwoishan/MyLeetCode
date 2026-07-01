class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxh = 0;
        int height = 0;
        int n = gain.size();
        for(int i = 0; i < n; i++){
            height += gain[i];
            maxh = max(maxh,height);
        }
        return maxh;
    }
};