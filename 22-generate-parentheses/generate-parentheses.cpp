class Solution {
public:
vector<string> ans;
string temp;
    void solve(int i, int j , int n){
        if(i + j == 2*n){
            ans.push_back(temp);
            return;
        }
        if(i < n){
            temp.push_back('(');
            solve(i+1,j,n);
            temp.pop_back();
        }
        if(j < i){
            temp.push_back(')');
            solve(i,j+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,n);
        return ans;
    }
};