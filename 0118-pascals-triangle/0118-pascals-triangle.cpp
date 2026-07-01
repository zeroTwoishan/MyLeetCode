class Solution {
public:
    /*int nCr(int n,int r){
        if(n==0 && r==0) return 1;
        if(r==0 && r==n){
            return n;
        }
        if(n-r<r){
            return nCr(n,n-r);
        
        }
        int res = 1;
        for(int i = 0;i<r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }*/
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        /*for(int i = 0;i<numRows;i++){
            vector<int> a;
            for(int j =0;j<=i;j++){
                a.push_back(nCr(i,j));
            }
            answer.push_back(a);
            
        }*/
        for(int i = 0;i<numRows;i++){
            vector<int> a(i+1,1);
            for(int j = 1;j<i;j++){
                a[j]=answer[i-1][j-1]+answer[i-1][j];
            }
            answer.push_back(a);
        }

        return answer;
    }
};