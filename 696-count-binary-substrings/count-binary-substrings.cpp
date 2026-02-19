class Solution {
public:
    int countBinarySubstrings(string s) {
        char prev = s[0];
        int i =0;
        int n = s.length();
        int count =0, curr1 = 0, curr2 = 0;
        while(i < n){
            if(prev == s[i]){
                curr1++;
                i++;
            }
            else{
                prev = s[i];
                while(i < n && s[i] == prev){
                    curr2++;
                    i++;
                }
                count += min(curr1,curr2);
                curr1 = curr2;
                curr2 = 0;   
            }
        }
        return count;
    }
};