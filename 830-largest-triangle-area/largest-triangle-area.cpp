class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double value = 0.00;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<n;j++){
                for(int k = 2;k<n;k++){
                    int x = points[i][0] * (points[j][1]-points[k][1]); 
                    int y = points[j][0] * (points[k][1] - points[i][1]);
                    int z = points[k][0] * (points[i][1] - points[j][1]);
                    double v = abs(x+y+z);
                    value = max(value, v);
                }
            }
        }
        return value/2;
    }
};