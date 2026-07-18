class Solution {
public:
    //global variables
    const int M = 1e9+7;
    vector<vector<vector<long long>>> dp;

    string subtract(string s){
        int i = s.size() -1;
        while(i >= 0 && s[i] == '0'){
            s[i] = '9';
            i--;
        }
        if(i >= 0) s[i]--;
        int pos = 0;
        while(pos < s.size()-1 && s[pos] == '0'){
            pos++;
        }
        return s.substr(pos);
    }
    long long solve(int i, int tight, long long sum, string &num, int min_sum, int max_sum){
        //base case
         if(sum > max_sum) return 0;

        if(i == num.size()){
            if(sum >= min_sum && sum <= max_sum) return 1;
            else return 0;
        }
    
        if(dp[i][tight][sum] != -1) return dp[i][tight][sum];

        int limit = tight ? num[i]  -'0' : 9;

        long long ans = 0;

        for(int d = 0;d<=limit;d++){
            ans = (ans + solve(i + 1, tight  && (d == limit), sum + d,num,min_sum,max_sum)) % M;
        }
        return dp[i][tight][sum] = ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        //initialization
        int n = num2.size();
        dp.assign(n+1,vector<vector<long long>>(2,vector<long long>(9*n+1,-1)));

        string L = subtract(num1);
        long long right = solve(0,1,0,num2,min_sum,max_sum);

        dp.assign(L.size()+1,vector<vector<long long>>(2,vector<long long>(9*L.size()+1,-1)));
        long long left = solve(0,1,0,L,min_sum,max_sum);
        return (((right - left) % M) + M) % M;
        
    }
};