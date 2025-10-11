class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(auto val : s){
            sum += val-'a'+1;
        }
        int x = 0;
        for(auto val : s){
            x += val -'a' + 1;
            if(x*2 == sum) return true;
        }
        return false;
    }
};