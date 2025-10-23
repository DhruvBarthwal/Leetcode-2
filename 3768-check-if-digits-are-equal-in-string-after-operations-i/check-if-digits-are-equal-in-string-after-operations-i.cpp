class Solution {
public:
    bool hasSameDigits(string s) {
        //initialization
        string val = s;
        int n = s.size();
        //traverse until s length is 2
        while(n > 2){
            string ans = "";
            for(int j = 1;j<val.size();j++){
                int a = val[j-1] - '0';
                int b = val[j] - '0';
                int sum = (a+b)%10;
                ans.push_back(sum + '0');
            }
            val = ans;
            n--;
        }
        return val[0] == val[1];

    }
};