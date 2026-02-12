class Solution {
public:
int solve(char x , char y, char z, string &s , int n){
     int maxi = 0;
        int i = 0;
        while(i<n){
            if(s[i] == z) {
                i++;
                continue;
            }

            unordered_map<int,int>mp;
            int cnt = 0;
            mp[cnt] = i;
            int j = i;
            while(j<n && s[j] != z){
                cnt += (s[j] == x)? -1: 1;
                if(mp.count(cnt)){
                    maxi = max(maxi, j-mp[cnt]+1);
                }
                else{
                    mp[cnt] = j+1;
                }
                j++;
            }
            i=j;
        }

        return maxi;
}
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        int cnt = 1;
        //for single character
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]) cnt++;
            else{
                ans = max(ans,cnt);
                cnt =1;
            }
        }
        ans = max(ans,cnt);
        //for double character
        ans = max(ans, solve('a','b','c',s,n));
        ans = max(ans, solve('a','c','b',s,n));
        ans = max(ans, solve('b','c','a',s,n));
        //for triple character
        map<pair<int,int> ,int> mp;
        mp[{0,0}] = -1;
        int ca = 0, cb = 0, cc = 0;
        for(int i =0;i<n;i++){
            if(s[i] == 'a') ca++;
            else if(s[i] == 'b') cb++;
            else if(s[i] == 'c') cc++;

            pair<int,int> key = {ca - cb, cb - cc};

            if(mp.count(key)){
                ans = max(ans , i - mp[key]);
            }
            else mp[key] = i;
        }
        return ans;
    }
};