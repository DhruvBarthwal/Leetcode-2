class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = numCourses;
        vector<int> indegree(m,0);
        vector<vector<int>>adj(m);
        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<m;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            count++;
            for(int &i : adj[x]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        return count == m;
    }
};