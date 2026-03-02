class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> temp;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 0) count++;
                else break;
            }
            temp.push_back(count);
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            int needed = n - i -1;
            int j = i;
            while(j < n && temp[j] < needed) j++;
            if(j == n) return -1;
            while(j > i){
                swap(temp[j],temp[j-1]);
                j--;
                ans++;
            }
        }
        return ans;
    }
};