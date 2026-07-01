/*class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mpp;
        int n = numbers.size();
        int i = 1;
        while(i < n + 1){
            int num = numbers[i - 1];
            if(mpp.count(target - num)){
                return {mpp[target - num],i};
            }
            mpp[num] = i;
            i++;
        }
        return {-1,-1};
    }
};*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while(i < j) {
            int sum = numbers[i] + numbers[j];

            if(sum == target) {
                return {i + 1, j + 1};
            }
            else if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {-1, -1};
    }
};