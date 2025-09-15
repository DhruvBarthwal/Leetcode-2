class Solution {
private:
    bool isPresent(char c, string brokenLetters){
        return brokenLetters.find(c) != string :: npos;
    }
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int value = 0;
        int count = 0;
        istringstream iss(text);
        string word;
        bool check = false;
        while(iss >> word){
            for(char ch : word){
                if(isPresent(ch, brokenLetters)){
                    count++;
                    break; 
                }
            }
            value++;
            check = false;
        }
        return value -count;
    }
};