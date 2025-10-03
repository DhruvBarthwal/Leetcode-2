class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if (n == 0) return 0;
        int m = heightMap[0].size();
        if (m == 0) return 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<pair<int, pair<int,int>>>> pq;

        // Step 1: Push all boundary cells into min-heap
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][m-1], {i,m-1}});
            visited[i][0] = visited[i][m-1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], {0,j}});
            pq.push({heightMap[n-1][j], {n-1,j}});
            visited[0][j] = visited[n-1][j] = true;
        }

        // Directions: up, down, left, right
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;

        // Step 2: Process heap
        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int i = pos.first, j = pos.second;

            for (auto &d : dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    // If neighbor is lower, water is trapped
                    res += max(0, h - heightMap[x][y]);
                    // Push effective boundary height
                    pq.push({max(h, heightMap[x][y]), {x,y}});
                }
            }
        }

        return res;
    }
};
