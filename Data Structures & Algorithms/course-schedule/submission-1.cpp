class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

         vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
         vector<int> visited (numCourses,false);

        for(vector<int>& vec: prerequisites){
            graph[vec[0]][vec[1]] = true; //znac ako imamo zavisnost 0,1 onda nam je (0,1) u matrici true
        }

         for(vector<int>& vec: prerequisites){
            if(checkForCycle(vec[0],graph,visited))return false;
         }
         return true;

        
    }
    bool checkForCycle(int node,vector<vector<bool>>& g, vector<int>& v){
        if(v[node] == -1)return true; //opet smo usli u neki koji analiziramo
        if(v[node] == 1)return false; //bezbedan node
        v[node] = -1;
        
        for(int i = 0;i<g.size();i++){
            
            if(g[node][i] && checkForCycle(i,g,v))return true;
                
            
        }
        v[node] = 1;
        return false;
    }
};
