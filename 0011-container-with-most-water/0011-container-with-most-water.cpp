class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxA = INT_MIN;
        while(i < j){
            int minh = min(height[i],height[j]);
            int dist = j - i;
            maxA = max(maxA,(minh * dist));
            if(height[i] == minh) i++;
            else j--;
        }
        return maxA;
    }
}; 