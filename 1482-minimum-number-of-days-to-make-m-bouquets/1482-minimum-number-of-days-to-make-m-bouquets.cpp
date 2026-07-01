class Solution {
public:
    int no_of(vector<int>& arr,int day,int k){
        int count = 0;
        int no = 0;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] <= day){
                count++;
                if(count == k){
                    no++;
                    count =0;
                }
            }
            else count = 0;
        }
        return no;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            int n = no_of(bloomDay,mid,k);
            if(n >= m) high = mid-1;
            else if (n<m) low = mid+1;
        }
        return (no_of(bloomDay,low,k) >= m)? low : -1 ;
    }
};