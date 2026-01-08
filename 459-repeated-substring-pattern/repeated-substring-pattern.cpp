class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s+s;
        string subset = temp.substr(1,temp.size()-2);
        return subset.find(s) != string :: npos;
    }
};