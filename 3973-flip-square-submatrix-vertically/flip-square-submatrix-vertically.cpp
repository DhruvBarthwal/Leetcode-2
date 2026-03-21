class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int b = k;
        int p = k/2;
        for(int i = x;i<x+p;i++){
            for(int j = y;j<y+k;j++){
                swap(grid[i][j], grid[x+b-1][j]);
            }
            b--;
        }
        return grid;
    }
};