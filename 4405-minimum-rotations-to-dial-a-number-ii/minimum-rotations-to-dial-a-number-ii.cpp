class Solution {
public:
    int dist(int a, int b){
        return min(abs(a-b) , 10 - abs(a-b));
    }
    int minRotations(int n, string s) {
        int ans = 0;
        int curr =0;
        for(char &ch : s){
            int num = ch -'0';
            ans += dist(num,curr);
            curr = num;
        }
        int original = ans;

        for(int k = 0;k<n;k++){
            int newCost;

            if(k == 0){
                int oldVal = dist(0, s[0] - '0');
                int newVal = dist(0, s[n-1] - '0');
                newCost = original - oldVal + newVal;
            }
            else{
                int oldVal = dist(s[k-1] -'0', s[k] - '0');
                int newVal = dist(s[k-1] - '0', s[n-1] - '0');
                newCost = original - oldVal + newVal;
            }
            ans = min(newCost, ans);
        }
        return ans;
    }
};