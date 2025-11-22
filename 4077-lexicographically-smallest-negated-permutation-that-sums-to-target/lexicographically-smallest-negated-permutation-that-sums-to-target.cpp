class Solution {
public:
long long sumVal(long long x){
    return (x)*(x+1)/2;
}
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long S = sumVal(n);
        if(target<-S || target > S) return {};

        vector<int> ans;
        for(int i = n;i>=1;i--){
            if(sumVal(i-1) - i >= target){
                target += i;
                ans.push_back(-i);
            }
            else{
                target -= i;
                ans.push_back(i);
            }
        }
        if(target != 0) return {};
        sort(ans.begin(),ans.end());
        return ans;

    }
};