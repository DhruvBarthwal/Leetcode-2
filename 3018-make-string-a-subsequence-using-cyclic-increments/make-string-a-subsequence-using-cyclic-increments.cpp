class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n = str1.size(), m = str2.size();
        if(n < m) return false;

        for(int i = 0;i<n;i++){
            int y = str2[j] - 'a';
            int x = str1[i] - 'a';
            int z = ((x+1) % 26);

            if(x == y || z == y) j++;
        }
        return j == m;
    }
};