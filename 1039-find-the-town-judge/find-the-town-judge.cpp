class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //adj list
        vector<int> indegree(n+1,0), outdegree(n+1,0);
        for(auto num : trust){
            int u = num[0];
            int v = num[1];
            outdegree[u]++;
            indegree[v]++;
        }
        //checking for judge
        int judge = -1;
        for(int i = 1;i<=n;i++){
            if(outdegree[i] == 0 && indegree[i] == n-1){
                judge = i;
            }
        }
        return judge;
    }
};