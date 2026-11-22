class Solution {
public:
    bool checkString(string s) {
        bool flag = 0;
        int n = s.size();

        for(int i = 0;i<n;i++){
            if(s[i] == 'b') flag = 1;
            else if(s[i] == 'a' && flag == 1) return false;
        }
        return true;
    }
};