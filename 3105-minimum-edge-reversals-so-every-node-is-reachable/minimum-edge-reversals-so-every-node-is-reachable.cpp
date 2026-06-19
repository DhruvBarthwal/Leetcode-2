class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;

    void dfs1(int node, int parent) {
        for (auto &[child, cost] : adj[node]) {
            if (child == parent) continue;

            ans[0] += cost;
            dfs1(child, node);
        }
    }

    void dfs2(int node, int parent) {
        for (auto &[child, cost] : adj[node]) {
            if (child == parent) continue;

            // Reroot from node -> child
            if (cost == 0)
                ans[child] = ans[node] + 1;
            else
                ans[child] = ans[node] - 1;

            dfs2(child, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        adj.resize(n);
        ans.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        // Compute answer for root = 0
        dfs1(0, -1);

        // Compute answers for all other roots
        dfs2(0, -1);

        return ans;
    }
};