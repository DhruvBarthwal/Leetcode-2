class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //intialization
        unordered_map<string,vector<int>> adj;
        int n = strs.size();
        //traverse the array
        for(int i = 0;i<n;i++){
            string val = strs[i];
            sort(val.begin(),val.end());
            adj[val].push_back(i);
        }
        //traversing the adj list
        vector<vector<string>> result;
        for(auto [x, str] : adj){
            vector<string> ans;
            for(auto y : str){
                ans.push_back(strs[y]);
            }
            result.push_back(ans);
        }
        return result;
    }
};