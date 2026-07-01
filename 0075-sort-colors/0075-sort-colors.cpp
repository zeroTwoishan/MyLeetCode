class Solution {
public:
    /*void merge(vector<int> &a,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if (a[left]<=a[right])
        {
           temp.push_back(a[left]);
           left++; 
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
        
    }
    while (left<=mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right<=high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = low; i <=high; i++)
    {
        a[i]=temp[i-low];
    }
}
void merge_sort(vector<int>&a,int low,int high){
    if (low>=high) return;   
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
    }*/
    void swap(int &a,int &b){
        int t = a;
        a=b;
        b=t;
    }
    void sortColors(vector<int>& nums) {
    int n=nums.size();
    int low = 0 ,mid = 0, high = n-1;
    while(mid<=high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid]==1) mid++;
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
};