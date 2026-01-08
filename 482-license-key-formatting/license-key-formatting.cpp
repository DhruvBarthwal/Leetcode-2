class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        string temp = "";
        int cnt = 0;
        for(int i = n-1;i>=0;i--){
            if(isalnum(s[i])){
                temp.push_back(toupper(s[i]));
                cnt++;
            }
            if(cnt == k && i > 0){
                temp.push_back('-');
                cnt = 0;
            }
        }
        if(!temp.empty() && temp.back() == '-') temp.pop_back();
        reverse(temp.begin(),temp.end());
        return temp;
    }
};