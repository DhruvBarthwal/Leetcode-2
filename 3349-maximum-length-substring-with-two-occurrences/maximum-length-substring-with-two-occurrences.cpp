class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        int i = 0;
        int ans = 0;
        for(int j = 0;j<n;j++){
            freq[s[j] - 'a']++;
            while(freq[s[j] - 'a'] > 2){
                freq[s[i] - 'a']--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};