class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for(int i = 0;i<n;i++){
            string str1 = s.substr(0,i+1);
            string str2 = s.substr(i+1,n);
            reverse(str1.begin(),str1.end());
            ans = min(ans,str1+str2);
            reverse(str2.begin(),str2.end());
            ans = min(ans,s.substr(0,i+1) + str2);
        }
        return ans;
    }
};