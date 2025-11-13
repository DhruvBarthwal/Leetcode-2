class Solution {
public:
    int maxOperations(string s) {
        int curr  = 0;
        int n = s.length();
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '1') curr++;
            else if(i>0 && s[i-1] == '1') ans += curr;
        }
        return ans;
    }
};