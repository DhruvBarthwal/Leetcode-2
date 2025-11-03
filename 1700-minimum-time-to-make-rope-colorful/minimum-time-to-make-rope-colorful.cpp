class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int n = neededTime.size();
        int maxi = neededTime[0];
        for(int i = 1; i<n;i++){
            if(colors[i] == colors[i-1]){
                if(neededTime[i] > maxi ){
                    time += maxi;
                    maxi = neededTime[i];
                }
                else{
                    time += neededTime[i];
                }
            }
            else{
                maxi = neededTime[i];
            }
        }
        return time;
    }
};