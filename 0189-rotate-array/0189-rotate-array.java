class Solution {
    public void rotate(int[] nums, int k) {
        if(nums.length==1){
            return;
        }
        if(k>nums.length){
            k=k%nums.length;
        }
        reverse(nums,0,nums.length-1-k);
        reverse(nums,nums.length-k,nums.length-1);
        reverse(nums,0,nums.length-1);


        // }
        // rotation(nums,k);

        
    }

    // static void rotation(int[] arr,int k){
    //     if(k==0){
    //         return;
    //     }

    //     int temp = arr[arr.length-1];
    //     for(int i =arr.length-2;i>=0;i--){
    //         arr[i+1]=arr[i];
    //     }
    //     arr[0]=temp;
    //     rotation(arr,k-1);
    // }



    static void reverse(int[] arr,int start,int end){
        int p=start;
        int q= end;
        while(p<q){
            //arr[p],arr[q]
            arr[p]= arr[p]+arr[q]-(arr[q]=arr[p]);
            p++;
            q--;
        }
    }
}