class Solution {
public:
int n, m;
bool checkRow(int j, vector<vector<int>>& mat){
    int cnt = 0;
    int i =0;
    while(i<n){
        if(mat[i][j] == 1) cnt++;
        i++;
    }
    return cnt == 1;
}
bool checkCol(int i, vector<vector<int>>& mat){
    int cnt = 0;
    int j = 0;
    while(j < m){
        if(mat[i][j] == 1) cnt++;
        j++;
    }
    return cnt == 1;
}
    int numSpecial(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        n = mat.size();
        m = mat[0].size();
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1) q.push({i,j});
            }
        }
        int count = 0;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(checkRow(y,mat) && checkCol(x,mat)) count++;
        }
        return count;
    }
};