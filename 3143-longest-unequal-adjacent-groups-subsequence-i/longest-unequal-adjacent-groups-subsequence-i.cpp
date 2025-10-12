class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        bool flag = (groups[0] == 0)? false : true;
        for(int i = 0;i<groups.size();i++){
            if(flag && groups[i] == 1){
                ans.push_back(words[i]);
                flag = !flag;
            }
            else if(!flag && groups[i] == 0){
                ans.push_back(words[i]);
                flag = !flag;
            }
        }
        return ans;
    }
};