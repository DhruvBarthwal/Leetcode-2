class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        set<int> s;
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            s.insert(nums[i]);
            mp[nums[i]]++;
        }
        
        vector<int> ans;

        while(!s.empty()){
            for(auto it = s.begin();it != s.end();){
                ans.push_back(*it);
                mp[*it]--;

                if(mp[*it] == 0) it = s.erase(it);
                else it++;
            }
        }
        return ans;
    }
};