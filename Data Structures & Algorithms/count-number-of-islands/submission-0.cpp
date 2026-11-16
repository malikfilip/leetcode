class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i =0;i<grid.size();i++){
             for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ret++;
                    traverse(i,j,grid);
                }
             }
        }
        return ret;
        
    }
    void traverse(int i, int j, vector<vector<char>>& graph){
        if(i<0 || j < 0 || i>=graph.size() || j>=graph[0].size() || graph[i][j] != '1')return;
        graph[i][j] = '0'; //posto cemo iz vise razlitih komsija doci ovde ne zelimo vise puta da ga obidjemo i udjemo u livelock
        traverse(i-1,j,graph);
        traverse(i+1,j,graph);
        traverse(i,j+1,graph);
        traverse(i,j-1,graph);
        //da ne invalidiramo ono mesto iznad ovde bi smo npr iz i-1,j koji moze biti 1 opet usli u samog sebe tj iz njegove perspektive u i+1,j i tako bismo se vrteli zauvek

    }
};
