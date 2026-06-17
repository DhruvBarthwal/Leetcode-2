class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(char &ch : s){
            if(ch == '*') len = max(0LL, len-1);
            else if(ch == '#') len *= 2;
            else if (ch != '%') len++;
        }
        int n = s.length();
        if(k >= len) return '.';
        for(int i = n-1;i>=0;i--){
            char ch = s[i];
            if(ch == '*'){
                len++;
            }
            else if(ch == '#'){
                long long half = len/2;
                if(k >= half) k-= half;
                len = half;
            }
            else if( ch == '%'){
                k = len - 1 - k;
            }
            else{
                if(k == len-1) return ch;
                len--;
            }
        }
        return '.';
    }
};