class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            } 
            else{
                char top = st.top();
                if(st.empty()) return false;
                if((top == '(' && ch == ')')
                 || (top == '{' && ch == '}')
                 || (top == '[' && ch == ']')) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};