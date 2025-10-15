class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //intialization
        unordered_map<string,vector<string>> adj;
        int n = strs.size();
        //traverse the array
        for(int i = 0;i<n;i++){
            string val = strs[i];
            sort(val.begin(),val.end());
            adj[val].push_back(strs[i]);
        }
        //traversing the adj list
        vector<vector<string>> result;
        for(auto &[x, ans] : adj){
            result.push_back(ans);
        }
        return result;
    }
};