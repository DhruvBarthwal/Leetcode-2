class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int>portal(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int j = st.top();
                st.pop();
                portal[i] = j;
                portal[j] = i;
            }
        }
        string res;
        for(int i = 0, dir = 1;i<n;i+=dir){
            if(s[i] >= 'a'){
                res += s[i];
            }
            else{
                i = portal[i];
                dir = -dir;
            }
        }
        return res;
    }
};