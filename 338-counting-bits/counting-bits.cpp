class Solution {
public:
    int solve(int num){
        int res = 0;
        while(num>0){
            if(num & 1){
                res++;
            }
            num >>=1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        //intialization
        vector<int> ans;
        for(int i = 0;i<=n;i++){
            int value = solve(i);
            ans.push_back(value);
        }
        return ans;
    }
};