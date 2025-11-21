class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> first(26,-1),last(26,-1);
        for(int i = 0;i<n;i++){
            char ch = s[i] - 'a';
            if(first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }
        for(int i =0;i<26;i++){
            if(first[i] == -1 || first[i] == last[i]) continue;

            int l = first[i];
            int r = last[i];
            vector<bool> seen(26,false);
            for(int j = l+1;j<r;j++){
                seen[s[j] - 'a'] = true;
            }
            ans += count(seen.begin(),seen.end(),true);
        }
        return ans;
    }
};