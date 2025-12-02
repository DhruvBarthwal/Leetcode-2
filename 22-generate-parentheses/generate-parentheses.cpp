class Solution {
public:
vector<string> ans;
string temp;
void solve(int left, int right, int n){
    //base case
    if(left + right == 2*n){
        ans.push_back(temp);
        return;
    }
    if(left < n ){
        temp.push_back('(');
        solve(left+1,right,n);
        temp.pop_back();
    }
    if(right < left){
        temp.push_back(')');
        solve(left, right +1, n);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        solve(0,0,n);
        return ans;
    }
};