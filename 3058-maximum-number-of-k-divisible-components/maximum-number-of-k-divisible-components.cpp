class Solution {
public:
    int ans = 0;
    int K;
    vector<vector<int>> adj;

    // returns subtree sum % K for node u
    long long dfs(int u, int parent, vector<int>& values) {
        long long s = ((long long)values[u]) % K;    // start with node's value mod K
        for (int v : adj[u]) {
            if (v == parent) continue;
            s += dfs(v, u, values);   // add child subtree (already mod K)
            s %= K;                   // keep it small to avoid overflow
        }

        if (s % K == 0) {
            ans++;     // this subtree can be cut as a valid component
            return 0;  // return 0 to parent because this subtree is removed
        }
        return s;      // otherwise return the remainder upward
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        K = k;
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        ans = 0;
        dfs(0, -1, values);
        return ans;
    }
};
