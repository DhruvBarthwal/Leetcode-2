class Solution {
public:
//Disclaimer!!! = Understand logic by ignoring 1LL
//1LL is used to nulify overflow
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Running cost : Sum of both cost individually
        long long runningCost = 1LL*(cost1 + cost2);

        long long val = min(runningCost,(long long)costBoth);

        //if need1 is greater : sum of (cost till need1 == need2) + (remaining need1 cost)
        if(need1 > need2){
            return (1LL * need2 * val) + (1LL * min(cost1,costBoth) *(need1 - need2));
        }
        //if need2 is greater : sum of (cost till need1 == need2) + (remaining need2 cost)
        else if(need2 > need1){
            return (1LL * need1 * val + 1LL * min(cost2,costBoth) *(need2 - need1));
        }
        //if need1 == need2
        return (1LL * need1 * val);
    }
};