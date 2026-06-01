class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size();
        int k = 0;
        int ans =0;
        for(int i = n-1;i>=0;i--){
            if(k == 2){
                k = 0;
                continue;
            }
            k++;
            ans += cost[i];
        }
        return ans;
    }
};