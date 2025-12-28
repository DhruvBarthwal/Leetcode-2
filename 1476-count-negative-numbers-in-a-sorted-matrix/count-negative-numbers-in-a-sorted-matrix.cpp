class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size() -1;
        int cols = grid[0].size() -1;
        while(rows>=0){
            for(int i = cols;i>=0;i--){
                if(grid[rows][i] < 0) count++;
                else break;
            }
            rows--;
        }
        return count;
    }
};