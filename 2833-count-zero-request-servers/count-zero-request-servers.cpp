class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int l = 0, r = 0;
        int active = 0;
        int m = queries.size();
        vector<int>ans(m);

        sort(logs.begin(),logs.end(),[](auto &a, auto &b){
           return a[1] < b[1];
        
        });

        vector<pair<int,int>> q;

        unordered_map<int,int> freq;
        
        for(int i = 0;i<m;i++){
            q.push_back({queries[i],i});
        }

        sort(q.begin(),q.end());

        for(auto &[time,idx] : q){
            int start = time - x;
            while(r < logs.size() && time >= logs[r][1]){
                int id = logs[r][0];
                freq[id]++;
                
                if(freq[id] == 1) active++;
                r++;
            }
            while(l < r && start > logs[l][1]){
                int id = logs[l][0];
                freq[id]--;
                if(freq[id] == 0) active--;
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};