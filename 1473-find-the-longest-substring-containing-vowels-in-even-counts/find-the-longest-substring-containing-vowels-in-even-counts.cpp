class Solution {
public:
bool isVowel(char &ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> check = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        int curr = 0;
        int ans = 0;
        int n = s.length();
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i =0;i<n;i++){
            if(isVowel(s[i])){
                curr ^= (1 << check[s[i]]);
            }
            if(mp.count(curr)){
                ans = max(ans, i - mp[curr]);
            }
            else mp[curr] = i;
        }      
        return ans;
    }
};