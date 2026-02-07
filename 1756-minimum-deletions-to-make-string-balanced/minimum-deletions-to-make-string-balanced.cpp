class Solution {
public:
    int minimumDeletions(string s) {
        int bcount = 0;
        int ans = 0;
        for(char &ch : s){
            if(ch == 'b'){
                bcount++;
            }
            else{
                ans = min(ans+1,bcount);
            }
        }
        return ans;
    }
};