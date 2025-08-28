class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //initialization
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int,priority_queue<int>> maxHeap;
        unordered_map<int,priority_queue<int,vector<int>, greater<int>>> minHeap;
        
        //adding the elements
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                int key = i-j;
                if(key<0){
                    minHeap[key].push(grid[i][j]);
                }
                else{
                    maxHeap[key].push(grid[i][j]);
                }
            }
        }
        //adding the sorted elements back to matrix
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                int key = i-j;
                if(key<0){
                    grid[i][j] = minHeap[key].top();
                    minHeap[key].pop();
                }
                else{
                    grid[i][j] = maxHeap[key].top();
                    maxHeap[key].pop();
                }
            }
        }
        return grid;
    }
};