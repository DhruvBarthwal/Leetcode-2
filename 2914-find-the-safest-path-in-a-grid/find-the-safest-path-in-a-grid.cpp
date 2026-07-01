class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(A[i][j]){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dist = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(auto [dx,dy] : dist){
                int x = i + dx;
                int y = j + dy;
                if(min(x,y) >= 0 && max(x,y) < n && !A[x][y]){
                    A[x][y] = A[i][j] + 1;
                    q.push({x,y});
                }
            }
        }
        priority_queue<tuple<int,int,int>> pq;
        pq.push({A[0][0],0,0});
        while(!pq.empty()){
            auto [sf,i,j] = pq.top();
            pq.pop();
            if(i == n-1 && j == m-1) return sf-1;
            for(auto [dx,dy] : dist){
                int x = i + dx;
                int y = j + dy;
                if(max(x,y) < n && min(x,y) >=0 && A[x][y] > 0){
                    pq.push({min(sf,A[x][y]),x,y});
                    A[x][y] *= -1;
                }
            }
        }
        return A.back().back() -1;
    }
};