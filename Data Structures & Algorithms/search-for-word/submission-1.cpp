class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        for(i = 0; i < board.size();i++){
            for(j=0;j<board[i].size();j++){

                if (board[i][j] == word[0] && backtrack(board,word,0,i,j))return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board,const string& word,int index,int row,int col){
        int rows = board.size();
        int cols = board[0].size();
        if(row < 0 || row == rows || col < 0 || col == cols)return false;
        if(board[row][col] != word[index]) return false;
        if(index + 1 == word.size())return true;
        char field = board[row][col];
        board[row][col] = '#';
        if (
           backtrack(board,word,index+1,row-1,col)
        || backtrack(board,word,index+1,row+1,col)
        || backtrack(board,word,index+1,row,col+1)
        || backtrack(board,word,index+1,row,col-1)
        )return true;
        board[row][col] = field;
        return false;

    }
};
