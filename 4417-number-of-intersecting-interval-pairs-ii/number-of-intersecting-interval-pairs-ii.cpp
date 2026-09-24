class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<>> pq;
        pq.push(intervals[0][1]);
        int n = intervals.size();
        long long count = 0;

        for(int i = 1;i<n;i++){
            while(!pq.empty() && pq.top() < intervals[i][0]){
                pq.pop();
            }
            count += pq.size();
            pq.push(intervals[i][1]);
        }
        return count;
    }
};