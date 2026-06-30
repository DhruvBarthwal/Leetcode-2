class Solution {
public:
    int numberOfSubstrings(string s) {
        int a =-1, b = -1, c = -1;
        int ans = 0;
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(ch == 'a') a = i;
            if(ch == 'b') b = i;
            if(ch == 'c') c = i;
            ans += min({a,b,c}) +1;
        }
        return ans;
    }
};