class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        vector<vector<int>> dis(n, vector<int>(m, -1));

        health -= grid[0][0];
        if (health <= 0) return false;

        queue<tuple<int,int,int>> q;
        q.push({0,0,health});
        dis[0][0] = health;

        while(!q.empty()){
            auto [i,j,h] = q.front();
            q.pop();

            if(i == n-1 && j == m-1)
                return true;

            for(auto &[dx,dy] : dir){
                int x = i + dx;
                int y = j + dy;

                if(x < 0 || y < 0 || x >= n || y >= m)
                    continue;

                int newH = h - grid[x][y];

                if(newH <= 0)
                    continue;

                if(dis[x][y] >= newH)
                    continue;

                dis[x][y] = newH;
                q.push({x,y,newH});
            }
        }

        return false;
    }
};