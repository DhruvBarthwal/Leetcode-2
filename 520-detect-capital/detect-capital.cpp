class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int lowerCount = 0;
        int upperCount = 0;
        for(int x : word){
            if(x >= 'a' && x <= 'z') lowerCount++;
            else if(x >= 'A' && x <= 'Z') upperCount++;
        }
        return (lowerCount == n || upperCount == n || upperCount == 1 && word[0] >='A' && word[0] <= 'Z');
    }
};