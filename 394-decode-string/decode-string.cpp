class Solution {
public:
    string decodeString(string s) {
        stack<string> s1;
        stack<int> s2;
        int currNum = 0;
        string currStr = "";
        int n = s.length();
        for(char &ch : s){
            if(ch == '['){
                s1.push(currStr);
                s2.push(currNum);
                currStr = "";
                currNum = 0;
            }
            else if(ch == ']'){
                int num = s2.top(); s2.pop();
                string prev  = s1.top(); s1.pop();
                string temp ="";
                while(num--){
                    temp += currStr;
                }
                currStr = prev + temp;
            }
            else if(isdigit(ch)){
                currNum = currNum*10 + (ch-'0');
            }
            else{
                currStr += ch;
            }
        }
        return currStr;
    }
};