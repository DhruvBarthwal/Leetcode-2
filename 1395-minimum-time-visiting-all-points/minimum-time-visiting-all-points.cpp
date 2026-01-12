class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        for(int i = 0;i<n-1;i++){
            int x = abs(points[i+1][0] - points[i][0]);
            int y = abs(points[i+1][1] - points[i][1]);
            time += min(x,y) + abs(x-y);
        }
        return time;
    }
};