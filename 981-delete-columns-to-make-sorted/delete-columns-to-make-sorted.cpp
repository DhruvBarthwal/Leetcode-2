class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int cols = 0;
        for(int i = 0;i<m;i++){
            int prev = strs[0][i] - 'a';
            for(int j = 1;j<n;j++){
                int val = strs[j][i] - 'a';
                if(prev > val){
                    cols++;
                    break;
                }
                prev = val;
            }
        }
        return cols;
    }
};