class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int index2 = n / 2;
        int index1 = index2 - 1;
        int index = 0;
        int i = 0 , j = 0;
        int element1 = INT_MIN,element2 = INT_MIN;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                if(index == index1) element1 = nums1[i];
                if(index == index2) element2 = nums1[i];
                i++;
                index++;
            }
            else{
                if(index == index1) element1 = nums2[j];
                if(index == index2) element2 = nums2[j];
                j++;
                index++;
            }
            if(element1 != INT_MIN && element2 != INT_MIN) break;
        }
        while(i < nums1.size()){
            if(index == index1) element1 = nums1[i];
            if(index == index2) element2 = nums1[i];
            i++;
            index++;
            if(element1 != INT_MIN && element2 != INT_MIN) break;
        }
        while(j < nums2.size()){
            if(index == index1) element1 = nums2[j];
            if(index == index2) element2 = nums2[j];
            j++;
            index++;
            if(element1 != INT_MIN && element2 != INT_MIN) break;
        }
        double ans = -1;
        if((nums1.size() + nums2.size()) % 2 == 0){
            ans = (double)(element1 + element2)/ 2.0;
        }
        else{
            ans = ((double)element2) ;
    }
    return ans;
    }
};