class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        for(int i = 0;i<m;i++){
            string ans;
            for(int j = 0;j<n;j++){
                if(j == 0 || i == m-1) ans.push_back('.');
                else ans.push_back('#');
            }
            res.push_back(ans);
        }
        return res;
    }
};