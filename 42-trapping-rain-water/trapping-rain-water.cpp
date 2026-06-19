class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int water = 0;
        int maxLeft = 0, maxRight = 0;
        while(left <= right){
            if(heights[left] <= heights[right]){
                if(maxLeft < heights[left]){
                    maxLeft = heights[left];
                }
                else{
                    water += maxLeft - heights[left];
                }
                left++;
            }
            else{
                if(maxRight < heights[right]){
                    maxRight = heights[right];
                }
                else{
                    water += maxRight - heights[right];
                }
                right--;
            }
        }
        return water;
    }
};