class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(char &ch : st){
            if(ch == '(' || ch == '{' || ch == '[') s.push(ch);
            else{
                if(s.empty()) return false;
                bool cond1 = s.top() == '(' && ch == ')';
                bool cond2 = s.top() == '{' && ch == '}';
                bool cond3 = s.top() == '[' && ch == ']';
                if(cond1 || cond2 || cond3){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};