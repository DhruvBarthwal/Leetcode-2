class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long runningCost = 1LL*(cost1 + cost2);
        long long val = min(runningCost,(long long)costBoth);
        if(need1 > need2){
            return 1LL * need2 * val + 1LL * min(cost1,costBoth) *(need1 - need2);
        }
        else if(need2 > need1){
            return 1LL * need1 * val + 1LL * min(cost2,costBoth) *(need2 - need1);
        }
        return 1ll * need1 * val;
    }
};