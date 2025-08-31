class Solution {
public:
bool isSafe(vector<vector<char>>&board,int row,int col,char val){
    for(int i=0;i<board.size();i++){
        //row check
        if(board[row][i]==val){
            return false;
        }
        //col check
        if(board[i][col]==val){
            return false;
        }
        //matrix check
        if(board[3*(row/3) + i/3][3*(col/3)+i%3] == val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    int n = board.size();
    for(int row = 0;row<n;row++){
        for(int col =0;col<n;col++){
            char ch = board[row][col];
            if(ch =='.'){
                for(int i=1;i<=9;i++){
                    char val = '0'+i;
                    if(isSafe(board,row,col,val)){
                        board[row][col] = val;
                        bool flag = solve(board);
                        if(flag){
                            return true;
                        }
                        else{
                            board[row][col] ='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};