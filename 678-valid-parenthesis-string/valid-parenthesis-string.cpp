class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        for(auto ch : s){
            if(ch == '('){
                open++;
                close++;
            }
            else if(ch==')'){
                open--;
                close--;
            }
            else{
                open++;
                close--;
            }
        if(open<0) return false;
        close = max(close,0);
        }
        return close==0;
    }
};