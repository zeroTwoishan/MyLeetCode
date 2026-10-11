class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        int leftMax = INT_MIN , rightMax = INT_MIN;
        for(int i = 0; i < n; i++){
            leftMax = max(height[i], leftMax);
            rightMax = max(height[n - 1 - i], rightMax);

            left[i] = leftMax;
            right[n - 1 - i] = rightMax;
        }
        int ans = 0;

        for(int i = 0; i < n; i++){
            int water = (min(left[i], right[i]) - height[i]);
            ans += water > 0 ? water : 0;
        }
        return ans;
    }
};