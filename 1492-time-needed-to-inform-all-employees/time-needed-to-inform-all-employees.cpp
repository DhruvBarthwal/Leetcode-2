class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //creating adj list
        unordered_map<int,list<int>> adj;
        for(int i = 0;i<n;i++){
            if(manager[i] != -1){
                int u = manager[i];
                adj[u].push_back(i);
            }
        }
        //time
        vector<int>time(n+1,INT_MAX);
        time[headID] = informTime[headID];
        //queue
        queue<pair<int,int>>q;
        q.push({headID,time[headID]});
        while(!q.empty()){
            auto [u , t] = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(time[v] > t + informTime[v]){
                    time[v] = t + informTime[v];
                    q.push({v,time[v]});
                }
            } 
        }
        int totalTime = 0;
        for(int i = 0;i<n;i++){
            if(time[i] != INT_MAX){
                totalTime = max(totalTime, time[i]);
            }
        }
        return totalTime;
    }
};