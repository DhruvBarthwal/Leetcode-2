class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        int limit = ceil(m/n);
        string temp = "";
        for(int i = 0;i<limit+2;i++){
            temp += a;
            if(temp.find(b) != string::npos){
                return i+1;
            }
        }
        return -1;
    }
};