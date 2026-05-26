class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> caps,small;
        for(char &ch : word){
            if(islower(ch)) small[ch]++;
            else caps[ch]++;
        }
        int ans = 0;
        for(auto &[ch,cnt] : caps){
            if(small.count(tolower(ch))) ans++;
        }
        return ans;
    }
};