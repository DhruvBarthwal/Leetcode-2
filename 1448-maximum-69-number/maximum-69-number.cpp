class Solution {
public:
    int maximum69Number (int num) {
        //initialization
        stack<int> s;
        bool flag = true;
        int ans = 0;
        while(num>0){
            int digit = num%10;
            s.push(digit);
            num /=10;
        }
        while(!s.empty()){
            int digit = s.top();
            s.pop();
            if(digit == 6 && flag){
                digit = 9;
                flag = false;
            }
            ans = ans*10 + digit;
        }
        return ans;
    }
};