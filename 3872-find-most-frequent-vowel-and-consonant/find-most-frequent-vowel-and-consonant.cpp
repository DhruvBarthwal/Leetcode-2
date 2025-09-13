class Solution {
private:
    bool isVowel(char c){
        return string("aeiou").find(c) != string::npos;
    }
public:
    int maxFreqSum(string s) {
        //initialization
        unordered_map<char,int> count;
        int vowel = 0;
        int consonent = 0;
        //traversing
        for(char ch : s){
            if(isVowel(ch)){
                count[ch]++;
                vowel = max(vowel,count[ch]);
            }
            else{
                count[ch]++;
                consonent = max(consonent, count[ch]);
            }
        }
        return vowel + consonent;
    }
};