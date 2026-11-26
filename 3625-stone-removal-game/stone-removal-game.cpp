class Solution {
public:
//10 9 8 7 6 5 4 3 2 1 
    bool canAliceWin(int n) {
        bool flag = false;
        for(int i = 10;i>0;i--){
            if(n < i) break;
            n -= i;
            flag = !flag;
        }
        return flag;
    }
};