class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return arr;          
        vector<pair<int,int>> temp;
        temp.reserve(n);
        for(int i = 0; i < n; i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());
        int rank = 1;
        arr[temp[0].second] = rank;
        for(int i = 1; i < n; i++){
            if(temp[i].first != temp[i-1].first) rank++;
            arr[temp[i].second] = rank;
        }
    return arr;
    }
};