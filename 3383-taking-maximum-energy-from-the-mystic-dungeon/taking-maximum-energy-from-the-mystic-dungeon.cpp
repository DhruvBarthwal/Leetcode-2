class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        //intialization
        int n = energy.size();
        vector<int> memo(n,0);
        int ans = INT_MIN;   //can be +ve or -ve
        //traversing the array in backwards
        for(int i = n-1;i>=0;i--){
            memo[i] = energy[i] + ((i+k < n) ? memo[i+k] : 0);
            //max energy
            ans = max(ans,memo[i]);
        }
        return ans;
    }
};