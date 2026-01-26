class Solution {
public:
int kmp(const string &txt, const string &patt){
    string newS = patt + "#" + txt;
    vector<int> lps(newS.length(), 0);

    int i = 1;
    int len = 0;

    while(i<newS.length()){
        if(newS[i] == newS[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len > 0){
                len = lps[len-1];
            }
            else{
                lps[0] = 0;
                i++;
            }
        }
    }
    return lps.back();
}
    string shortestPalindrome(string s) {
        int count = kmp(string(s.rbegin(),s.rend()),s);
        return string(s.rbegin(),s.rend()).substr(0,s.length()-count) + s;
    }
};