class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int cnt = 1;
        for(auto &i : temp){
            if(!mp.count(i)){
                mp[i] = cnt++;
            }
        }
        vector<int> ans;
        for(auto &i : arr){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};