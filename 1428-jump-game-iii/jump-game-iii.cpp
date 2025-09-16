class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //initialization
        queue<pair<int,int>> q;
        int n = arr.size();
        vector<bool> vis(n,false);
        //using queue
        q.push({start,arr[start]});
        while(!q.empty()){
            auto [index, value] = q.front();
            q.pop();
            if(value == 0){
                return true;
            }
            int pos1 = index - value;
            int pos2 = index + value;
            if(pos1 >=0 && !vis[pos1]){
                vis[pos1] = true;
                q.push({pos1, arr[pos1]});
            }
            if(pos2 < n && !vis[pos2]){
                vis[pos2] = true;
                q.push({pos2, arr[pos2]});
            }
        }
        return false;
    }
};