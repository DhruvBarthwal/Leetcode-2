class Solution {
public:
    //Step 1 : Create kernel for each node (Mathematical Part)
    long long kernel(long long num){
        long long res  = 1;
        for(long long i = 2; i*i<= num;i++){
            int count = 0;
            while(num % i == 0){
                num /= i;
                count ^=1; //Toggle btw 0 and 1 (Even(Perfect square) = 0 and Odd(Kernel) = 1)
            }
            if(count){
                res*=i; //kernel value
            }
        }
        if(num > 1){
            res *= num; //Handle prime numbers
        }
        return res;
    }
    //Step 3 : DFS
    void dfs(int node, int parent,long long &ans,unordered_map<long long,int> &freq,unordered_map<int, list<int>> &adj,vector<long long>& k){

        long long kernel = k[node];
        ans += freq[kernel]; 
        freq[kernel]++;

        for(auto neigh : adj[node]){
            if(neigh != parent){
                dfs(neigh,node,ans,freq,adj,k);
            }
        }
        //back track (if reach the leaf node)
        freq[kernel]--;
        if(freq[kernel] == 0){
            freq.erase(kernel);
        }
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        //Step 1: Create a bidirected graph
        unordered_map<int, list<int>> adj;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //Storing kernel for each node
        vector<long long> k(n);
        for(int i =0;i<n;i++){
            k[i] = kernel(nums[i]);
        }
        //dfs traversal
        long long ans = 0;
        unordered_map<long long,int> freq;  //store freq of kernel
        dfs(0,-1,ans,freq,adj,k);
        return ans;
    }
};