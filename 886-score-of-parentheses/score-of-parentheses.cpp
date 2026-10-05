class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, cnt = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
                if(s[i-1] == '('){
                    ans += 1 << cnt;
                }
            }
        }
        return ans;
    }
};