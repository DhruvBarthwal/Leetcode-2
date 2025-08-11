class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        //initialization
        constexpr int MOD = 1e9+7;
        vector<int> pow;
        vector<int> result;
        //adding power of 2 up to n
        for(int b = 0;b<31;b++){
            if(n & (1<<b)){
                pow.push_back(1<<b);
            }
        }
        //finding the peoduct array
        for(auto& num : queries){
            long long prod = 1;
            for(int i = num[0];i<=num[1];i++){
                prod = prod*pow[i] % MOD;
            }
            result.push_back((int)prod);
        }
        return result;
    }
};