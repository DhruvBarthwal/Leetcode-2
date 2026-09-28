class Solution {
public:
    int minOperations(int n) {
        if(n == 1) return 0;
        int ans = 0;

        if(n & 1){
            int index = (n-1)/2;
            int mid = 2 *(index) + 1;

            for(int i = 0;i<index;i++){
                int num = 2*i + 1;
                ans += mid - num;
            }
        }
        else{
            int index = (n-1)/2;
            int mid = 2*(index) + 2;

            for(int i =0;i<=index;i++){
                int num = 2*i+1;
                ans += mid - num;
            }
        }
        return ans;
    }
};