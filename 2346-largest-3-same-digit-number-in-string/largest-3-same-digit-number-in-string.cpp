class Solution {
public:
    string largestGoodInteger(string num) {
        //initialization
        string result = "";
        int n = num.length();
        for(int i = 0;i<=n-3;i++){
            string sub = num.substr(i,3);
            if(sub[0]==sub[1] && sub[1]== sub[2]){
                if(result.empty() || sub > result){
                    result = sub;
                }
            }
        }
        return result;
    }
};