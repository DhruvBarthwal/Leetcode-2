class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n+1,0);
        vector<int> concat(n+1,0);
        vector<int> length(n+1,0);
        vector<long long> p(n+1,0);
        vector<int> ans;
        const int M = 1e9+7;

        p[0] = 1;
        for(int i = 0;i<n;i++){
            p[i+1] = (p[i] * 10LL) % M;
        }
        for(int i =0;i<n;i++){
            prefix[i+1] = prefix[i] + (s[i] - '0');
            if(s[i] != '0'){
                length[i+1] = length[i] + 1;
                concat[i+1] = (concat[i]*10LL + (s[i] - '0')) % M; 
            }
            else{
                concat[i+1] = concat[i];
                length[i+1] = length[i];
            }
        }

        for(auto &q : queries){
            int sum = (prefix[q[1] + 1] - prefix[q[0]]) % M;
            
            int num1 = concat[q[1] + 1], num2 = concat[q[0]];
            int len1 = length[q[1] + 1], len2 = length[q[0]];

            long long power = p[length[q[1] + 1] - length[q[0]]];  
            long long temp = (1LL * num2 * power) % M;

            long long x = (num1 - temp + M) % M;
            long long value = (x*sum) % M;
            
            ans.push_back(value);
        }
        return ans;
    }
};