class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        int l = 0, r= n-1;
        while(l<r){
            int h = min(height[l],height[r]);
            int b = r-l;
            area = max(area,h*b);
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return area;
    }
};