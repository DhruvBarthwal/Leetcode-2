class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        int n = rows;
        int m = len/n;
        if(rows == 1) return encodedText;
        string res;
        for(int j = 0;j<m;j++){
            int k = j, i = 0;
            while(i<n && k<m){
                res += encodedText[i*m + k];
                k++;
                i++;
            }
        }
        while(!res.empty() && res.back() == ' '){
            res.pop_back();
        }
        return res;
    }
};