class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        

        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> ret;

        //pisemo koja sva polja mogu da dodju ako se od okeana krece nagore
        //na kraju vratimo samo polja koja su oba true
        if(heights.size() == 0)return ret;

        for(int n = 0;n<heights[0].size();n++){//obilazan pacifika
            traverseOcean(0,n,heights,pacific);
            traverseOcean(heights.size()-1,n,heights,atlantic );

        }
        for(int n = 0;n<heights.size();n++){//obilazan pacifika
            traverseOcean(n,0,heights,pacific);
            traverseOcean(n,heights[0].size()-1,heights,atlantic );

        }
        for(int i = 0; i < heights.size();i++){
            for(int j = 0; j <heights[0].size();j++){
                if(pacific[i][j] && atlantic[i][j])ret.push_back({i,j});
            }
        }

        return ret;
    }
    void traverseOcean(int i, int j, vector<vector<int>>& island,vector<vector<bool>>& ocean){
            //Ako smo ovde usli ovo polje sigurno moze da se dosegne iz PACIFIKA, znaci ovde ne ulazis uopste, provera mora pre poziva rekurzije.
            ocean[i][j] = true;
            if(i != 0 && island[i-1][j] >= island[i][j] && !ocean[i-1][j])traverseOcean(i-1,j,island,ocean);
            if(j != 0 && island[i][j-1] >= island[i][j] && !ocean[i][j-1])traverseOcean(i,j-1,island,ocean);
            if(i != island.size()-1 && island[i+1][j] >= island[i][j] && !ocean[i+1][j])traverseOcean(i+1,j,island,ocean);
            if(j != island[0].size()-1 && island[i][j+1] >= island[i][j] && !ocean[i][j+1])traverseOcean(i,j+1,island,ocean);
            
        }
  
};
