class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> arr;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int val = arr[0] % x;
        for(int i =0;i<arr.size();i++){
            if(arr[i] % x != val) return -1;
        }
        int ans = 0;
        int mid = arr[arr.size()/2];
        for(int i = 0;i<arr.size();i++){
            ans += abs(arr[i] - mid) / x;
        }
        return ans;
    }
};