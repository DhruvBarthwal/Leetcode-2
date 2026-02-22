class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int count = 0;
        while(n > 0){
            int a = n & 1;
            if(count != 0 && a == 1){
                ans = max(count,ans);
                count = 1;
            }
            else if(count == 0 && a == 1){
                count++;
            }
            else if(count != 0 && a == 0){
                count++;
            }
            n >>= 1;
        }
        return ans;
    }
};