class Solution {
public:
    /*
    int countOnes(vector<vector<int>>& img1, vector<vector<int>>& img2,int m, int n){
        int s = img1.size();
        int count = 0;
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                int row = i + m;
                int col = j + n;

                if (row >= 0 && row < s && col >= 0 && col < s) {
                    if (img1[i][j] == 1 && img2[row][col] == 1) count++;
                }
            }
        }
        return count;
    }
    */
    int countOnes(vector<vector<int>>& img1, vector<vector<int>>& img2, int dx, int dy) {
        int n = img1.size();
        int count = 0;
        for (int i = max(0, -dx); i < min(n, n - dx); i++)
            for (int j = max(0, -dy); j < min(n, n - dy); j++)
                if (img1[i][j] && img2[i + dx][j + dy]) count++;
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int i = -n + 1; i < n; i++){
            for(int j = -n + 1; j < n; j++){
                ans = max(countOnes(img1,img2,i,j),ans);
            }
        }
        return ans;
    }
};