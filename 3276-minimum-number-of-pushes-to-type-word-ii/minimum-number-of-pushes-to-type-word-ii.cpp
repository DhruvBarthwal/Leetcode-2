class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26,0);
        string word2;

        for(char &ch : word){
            freq[ch-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());

        int pushes = 0;
        for(int i=0;i<26 && freq[i] > 0;i++){
            pushes += (i/8 + 1)*freq[i];
        }   
        return pushes;
    }
};