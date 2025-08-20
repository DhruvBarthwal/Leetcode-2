class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //initialization
        int count = 0;
        int n = matrix.size(), m = matrix[0].size();
        //for initial row
        for(int i = 0;i<m;i++){
            count += matrix[0][i];
        }
        for(int i =1;i<n;i++){
                count += matrix[i][0];
        }
        //traversing the whole array
        for(int i =1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j] == 0) continue;
                matrix[i][j] = 1 + min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]});
                count+= matrix[i][j];
            }
        }
        return count;
    }
};