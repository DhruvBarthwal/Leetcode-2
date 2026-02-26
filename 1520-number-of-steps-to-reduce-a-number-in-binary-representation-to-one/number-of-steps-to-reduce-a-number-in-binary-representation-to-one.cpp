class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        while(s != "1"){
            int m = s.size();
            if(s.back() == '1'){
                int m = s.size();
                int i = m-1;
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                if(i >= 0) s[i] = '1';
                else s = "1" + s;
            }
            else{
                s.pop_back();
            }
            cnt++;
        }
        return cnt;
    }
};