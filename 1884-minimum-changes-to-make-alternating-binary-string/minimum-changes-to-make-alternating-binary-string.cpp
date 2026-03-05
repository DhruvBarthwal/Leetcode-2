class Solution {
public:
int solve(bool flag, int n, string &s){
    int cnt = 0;
    for(char &ch : s){
        if((flag && ch == '1') ||(!flag && ch == '0')) cnt++;
        flag = !flag;
    }
    return cnt;
}
    int minOperations(string s) {
        int n = s.size();
        int odd = solve(false,n,s);
        int even = solve(true,n,s);
        return min(odd, even);
    }
};