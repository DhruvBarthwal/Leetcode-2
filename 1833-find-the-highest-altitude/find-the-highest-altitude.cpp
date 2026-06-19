class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int prev = 0;
        int n = gain.size();
        for(int i =0;i<n;i++){
            int x = gain[i] + prev;
            maxi = max(maxi,x);
            prev = x;
        }
        return maxi;
    }
};