class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tails;
        vector<int> ans;
        for(int x : obstacles){
            int idx = upper_bound(tails.begin(),tails.end(),x) - tails.begin();
            if(idx == tails.size()) tails.push_back(x);
            else tails[idx] = x;
            ans.push_back(idx+1);
        }
        return ans;
    }
};