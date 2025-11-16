class NumMatrix {
    int n ,m;
    vector<vector<int>> bit;
    vector<vector<int>> mat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        bit.assign(n+1, vector<int>(m+1, 0));
        mat.assign(n, vector<int>(m, 0));  // IMPORTANT FIX

        // Build BIT using update()
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - mat[row][col];
        mat[row][col] = val;

        for(int i = row + 1; i <= n; i += (i & -i)){
            for(int j = col + 1; j <= m; j += (j & -j)){
                bit[i][j] += delta;
            }
        }
    }

    int query(int x, int y){
        int ans = 0;
        for(int i = x + 1; i > 0; i -= (i & -i)){
            for(int j = y + 1; j > 0; j -= (j & -j)){
                ans += bit[i][j];
            }
        }
        return ans;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2, col2)
             - query(row1 - 1, col2)
             - query(row2, col1 - 1)
             + query(row1 - 1, col1 - 1);
    }
};
