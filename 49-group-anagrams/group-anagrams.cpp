class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(auto &s : strs){
            string t = s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        for(auto &[x,y] : mp){
            res.push_back(y);
        }
        return res;
    }
};