class Solution {
public:
bool isBalanced(vector<int>&freq, int target){
    for(auto f : freq){
        if(f!=0 && f!= target){
            return false;
        }
    }
    return true;
}
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            vector<int>freq(26,0);
            for(int j = i;j<n;j++){
                freq[s[j]-'a']++;
                int target = freq[s[j]-'a'];
                if(isBalanced(freq,target)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};