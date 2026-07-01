/*class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxE = *max_element(arr.begin(),arr.end());
        for(int i = 0; i < n - 1; i++){
            if(arr[i] == maxE) maxE = *max_element(arr.begin() + i + 1,arr.end());
            arr[i] = maxE;
        }
        arr[n - 1] = -1;
        return arr;
    }
};*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxE = -1;

        for(int i = n - 1; i >= 0; i--){
            int newMax = max(maxE, arr[i]);
            arr[i] = maxE;
            maxE = newMax;
        }
        return arr;
    }
};