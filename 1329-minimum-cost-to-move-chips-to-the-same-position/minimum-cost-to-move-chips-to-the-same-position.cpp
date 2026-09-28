class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int,int> mp;
        
        for(auto &x : position){
            mp[x]++;
        }

        int oddCounts = 0, evenCounts = 0;
        int oddValues = 0, evenValues = 0;
        int even = -1 , odd = -1;

        for(auto &[x,y] : mp){
            if(x & 1){
                oddCounts++;
                oddValues += y;
                if(odd == -1) odd = x;
            }
            else {
                evenCounts++;
                evenValues += y;
                if(even == -1) even = x;
            }
        }

        if(oddCounts == 0 || evenCounts == 0) return 0;
        int ans = 0;
        if(oddCounts > evenCounts){
            ans = evenValues;
        }
        else if(evenCounts > oddCounts){
            ans = oddValues;
        }
        else{
            ans = min(evenValues,oddValues);
        }
        return ans;
    }
};