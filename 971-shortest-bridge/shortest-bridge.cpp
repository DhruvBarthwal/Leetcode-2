class Solution {
private:
    void dfs(int i, int j, vector<pair<int, int>>& dis, int n,
             queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        q.push({i, j});

        for (auto [dx, dy] : dis) {
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                dfs(x, y, dis, n, q, grid);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        // initialization
        vector<pair<int, int>> dis = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size();
        bool found = false;
        queue<pair<int, int>> q;
        int steps = 0;
        // inserting the first island in queue
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, dis, n, q, grid);
                    found = true;
                }
            }
        }
        // finding the shortest path from the irst island
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) { // process one full layer
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dis) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && j >= 0 && i < n && j < n) {
                        if (grid[i][j] == 1) {
                            return steps;
                        } else if (grid[i][j] == 0) {
                            grid[i][j] = 2;
                            q.push({i, j});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};