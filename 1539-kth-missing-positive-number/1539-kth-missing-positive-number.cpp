class Solution {
public:
    /*
          ##### O(nlogn) #####
    bool search(vector<int>& arr, int target){
        int low = 0;
        int high = arr.size() - 1;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(arr[mid]==target) return true;
            else if (arr[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 1;
        int count=0;
        while(count < k){
            if(!(search(arr,i))){
                count++;
            }
            i++;
        }
        return i-1;
    }*/
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            int missing = arr[mid] - mid -1;
            if(missing<k) low = mid+1;
            else high = mid-1;
        }
        return high + 1 + k;
    }
};