class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        //intialization
        int maxDiag = 0;
        int maxArea = 0;
        for(auto num : dimensions){
            int diagonal =  (num[0]*num[0]) + (num[1]*num[1]);
            int area = num[0]*num[1];
            if(diagonal> maxDiag || (diagonal == maxDiag && area > maxArea)){
                maxDiag = diagonal;
                maxArea = area;
            }
        }
        return maxArea;
    }
};