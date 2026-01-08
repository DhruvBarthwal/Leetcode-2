class Solution {
public:
    bool rotateString(string s, string goal) {
        if( s == goal) return true;
        int n = s.length();
        for(int i = 1;i<n;i++){
            string first = s.substr(0,i);
            string last = s.substr(i);
            string temp = last + first;
            if(temp == goal){
                return true;
                break;
            }
        }
        return false;
    }
};