class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int mini = INT_MAX;
        int negCount = 0;
        int zeroCount = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] < 0) negCount++;
                if(matrix[i][j] == 0) zeroCount++;
                mini = min(mini,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(negCount % 2 == 0 || zeroCount > 0) return sum;
        return sum - 2*mini;
    }
};