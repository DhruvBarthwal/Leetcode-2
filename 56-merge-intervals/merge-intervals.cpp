class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort
        sort(intervals.begin(),intervals.end());
        //initialization
        vector<vector<int>> res;
        int start = INT_MAX, end = INT_MAX;
        int n = intervals.size();

        //edge case
        if(n == 1) return intervals;

        for(int i =0;i<n;i++){
            if(start == INT_MAX || end == INT_MAX){
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else if(end >= intervals[i][0]){
                end = max(end,intervals[i][1]);
            }
            else{
                res.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start,end});

        return res;
    }
};