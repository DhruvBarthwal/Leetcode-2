class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        int res = 0;
        for(char &ch : s){
            if(ch == 'b') count++;
            else if(count != 0){
                res++;
                count--;
            }
        }
        return res;
    }
};