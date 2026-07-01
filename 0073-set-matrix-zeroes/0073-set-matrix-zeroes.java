class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] rows = new int[m*n];
        int[] columns = new int[m*n];
        int p=0;
        //
        for(int i=0;i<matrix.length;i++){
            for(int j =0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    rows[p]=i+1;
                    columns[p]=j+1;
                    p++;
                }

            }
        }

        


        
        


        for(int r :rows){
            if(r==0){
                break;
            }
            setRows(matrix,r);
        }

        for(int c :columns){
            if(c==0){
                break;
            }
            setColumns(matrix,c);
        }
        
    }



    static void setRows(int[][] arr,int r){
            for(int i=0;i<arr[0].length;i++){
                arr[r-1][i]=0;

            }

    }



    static void setColumns(int[][] arr,int c){
            for(int i=0;i<arr.length;i++){
                arr[i][c-1]=0;
            }
    }
}