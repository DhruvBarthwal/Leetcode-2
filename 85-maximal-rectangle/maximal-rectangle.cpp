class Solution {
public:
int solve(vector<int> &heights){
    stack <int> s;
    int area = 0;
    heights.push_back(0);
    for(int i = 0;i<heights.size();i++){
        while(!s.empty() && heights[i] < heights[s.top()]){
            int h = heights[s.top()];
            s.pop();

            int w = s.empty() ? i : i - s.top() - 1;
            area = max(area,w*h);
        }
        s.push(i);
    }
    heights.pop_back();
    return area;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m,0);
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, solve(heights));
        }
        return maxArea;
    }
};