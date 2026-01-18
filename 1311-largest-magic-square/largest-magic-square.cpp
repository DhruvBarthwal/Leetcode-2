class Solution {
public:
bool isValid(int i, int j, int k,vector<vector<int>>&grid){
    int sum = 0;
    //check row
    for(int x = i;x<i+k;x++){
        int s = 0;
        for(int y = j; y<j+k; y++) s += grid[x][y];
        if(x == i) sum = s;
        else if (sum != s) return false;
    }
    //check column
    for(int y = j;y<j+k;y++){
        int s = 0;
        for(int x = i;x<i+k;x++) s+= grid[x][y];
        if(sum != s) return false;
    }
    //left diagonal
    int s = 0;
    for(int d = 0;d<k;d++) s+= grid[i+d][j+d];
    if(sum != s) return false;
    //right diagonal
    s = 0;
    for(int d = 0;d<k;d++) s+= grid[i+d][j+k-1-d];
    if(sum != s) return false;

    return true;
}
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        for(int k=min(n,m);k>=2;k--){
            for(int i = 0;i+k<=n;i++){
                for(int j = 0;j+k<=m;j++){
                    if(isValid(i,j,k,grid)) return k;
                }
            }
        }
        return 1;
    }
};