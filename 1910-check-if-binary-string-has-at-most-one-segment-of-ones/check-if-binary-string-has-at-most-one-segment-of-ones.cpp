class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        int n = s.size();
        int i =0;
        while(i < n && s[i] == '0'){
            i++;
        }
        while(i < n){
            if(i < n && s[i] =='1'){
                count++;
                while(i< n-1 && s[i] == s[i+1]){
                    i++;
                }
            }
            i++;
        }
        return count == 1;
    }
};