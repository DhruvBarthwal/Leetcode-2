class Solution {
public:
bool isPalindrome(string &s){
    int i =0, j = s.size() -1;
    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
    int countSubstrings(string s) {
        int n = s.size();
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                string st = s.substr(i,j-i+1);
                if(isPalindrome(st)) ans++;
            }
        }
        return ans;
    }
};