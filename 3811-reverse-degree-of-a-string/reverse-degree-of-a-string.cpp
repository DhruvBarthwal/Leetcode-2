class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int i = 1;
        for(char &ch: s){
            int val = 26 - (ch -'a');
            sum += (i * val);
            i++;
        }
        return sum;
    }
};