class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        istringstream val(s);
        string word;
        while(val >> word){
            ans = " " + word + ans; 
        }
        return ans.substr(1,n);
    }
};