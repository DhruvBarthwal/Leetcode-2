class Solution {
public:
bool checkRow(int row , int col , int sum,vector<vector<int>>& grid){
    int sum1 = grid[row-1][col-1] + grid[row-1][col] + grid[row-1][col+1];
    int sum2 = grid[row][col-1] + grid[row][col] + grid[row][col+1];
    int sum3 = grid[row+1][col-1] + grid[row+1][col] + grid[row+1][col+1];
    return (sum1 == sum2) && (sum2 == sum3) && (sum3 == sum);
}
bool checkCol(int row, int col , int sum,vector<vector<int>>& grid){
    int sum1 = grid[row-1][col-1] + grid[row][col-1] + grid[row+1][col-1];
    int sum2 = grid[row-1][col] + grid[row][col] + grid[row+1][col];
    int sum3 = grid[row-1][col+1] + grid[row][col+1] + grid[row+1][col+1];
    return (sum1 == sum2) && (sum2 == sum3) && (sum3 == sum);

}
bool validate(int row , int col ,vector<vector<int>>& grid){
    unordered_map<int,int>mp;
    for(int i = row-1;i<=row+1;i++){
        for(int j = col-1;j<=col+1;j++){
            int value = grid[i][j];
            if(mp.count(value) || value <1 || value > 9){
                return false;
            }
            else{
                mp[value]++;
            }
        }
    }
    return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n <3 || m <3) return 0;

        int count = 0;

        for(int row = 1;row < n-1;row++){
            for(int col = 1;col< m-1;col++){
                int sum = grid[row][col] + grid[row-1][col] + grid[row + 1][col];
                bool cond1 = checkRow(row,col,sum,grid);
                bool cond2 = checkCol(row,col,sum,grid);
                bool cond3 = (grid[row][col] + grid[row-1][col-1] + grid[row + 1][col + 1]) == sum;
                bool cond4 = (grid[row][col] + grid[row-1][col+1] + grid[row+1][col-1]) == sum;
                bool cond5 = validate(row,col,grid);
                if(cond1 && cond2  && cond3 && cond4 && cond5){
                    count++;
                }
            }
        }
        return count;
    }
};