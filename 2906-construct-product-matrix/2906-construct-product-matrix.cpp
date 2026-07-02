class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = 12345;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> mat(row, vector<int>(col, 0)); 
        long long leftP = 1;
        long long rightP = 1;
        //Left Pass
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                mat[i][j] = leftP;
                leftP = (leftP * grid[i][j]) % m;
            }
        }
        //Right Pass
        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                mat[i][j] = (mat[i][j] * rightP) % m;
                rightP = (rightP * grid[i][j]) % m;
            }
        }  
        return mat;       
    }
};