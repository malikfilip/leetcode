class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Ulazi se dobijaju kao broj posmatranog*vrednost u polju
        //Npr 1. red i broj 3 ce u polje 1*3 upisati true, ako kasnije jos neko polje koje je 3 se nalazi u 1. redu, videce da je
        //ono vec true i vratiti false;

        vector<bool> visitedRow (81,false);
        vector<bool> visitedCol (81,false);
        vector<bool> visitedBox (81,false);

        for(int i = 0;i < board.size();i++){
            for(int j = 0;j <board.size();j++){
                if(board[i][j] == '.')continue;
                int val = board[i][j] - 49; //49 je ascii za 1
                if(visitedRow[i*9+val] || visitedCol[j*9+val] || visitedBox[((i/3)*3 + j/3)*9+val])return false;
                visitedRow[i*9+val] = true;
                visitedCol[j*9+val]=true;
                visitedBox[((i/3)*3 + j/3)*9+val] = true;
            }
        }
        return true;
    }
};
