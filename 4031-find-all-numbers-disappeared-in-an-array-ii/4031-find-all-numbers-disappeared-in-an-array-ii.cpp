class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> present(upper + 1, false);

        for(auto num : nums){
            if(num <= upper)
            present[num] = true;
        }
        int i = lower;

        vector<vector<int>> ans;

        while(i < upper + 1){
            if(present[i]){
                i++;
                continue;
            }
            vector<int> temp;
            temp.push_back(i);
            for(int j = i + 1; j < upper + 1; j++){
                if(present[j]){
                    temp.push_back(j - 1);
                    break;
                }
            }
            if(temp.size() == 1){
                temp.push_back(upper);
            }
            ans.push_back(temp);
            i = (temp.back() + 1);
        }
        return ans;
    }
};