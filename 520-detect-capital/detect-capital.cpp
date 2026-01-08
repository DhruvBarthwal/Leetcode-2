class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int lowerCount = 0;
        int upperCount = 0;
        for(int x : word){
            if(islower(x)) lowerCount++;
            else if(isupper(x)) upperCount++;
        }
        return (lowerCount == n || upperCount == n || upperCount == 1 && isupper(word[0]) );
    }
};