class Solution {
public:
    string maskPII(string s) {
        //email
        if(s.find('@') != string :: npos){
            transform(s.begin(),s.end(),s.begin(), ::tolower);
            int at = s.find('@');
            return s.substr(0,1) + "*****" + s.substr(at-1);
        }
        //phone number
        string digits = "";
        for(char ch : s){
            if(isdigit(ch)) digits.push_back(ch);
        }
        int n = digits.size();
        string local = "***-***-" + digits.substr(n-4);
        if(n == 10) return local;
        return "+" + string(n-10,'*') + "-" +  local;
    }
};