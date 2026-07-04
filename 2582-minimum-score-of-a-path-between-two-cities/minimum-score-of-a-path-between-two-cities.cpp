class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        int ans = INT_MAX;
        queue<int> q;
        vector<bool> vis(n+1, false);
        vis[1] = true;
        q.push(1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &[neigh,d] : adj[node]) {
                ans = min(d,ans);
                if (!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        return ans;
    }
};