class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
         vector<vector<int>> neighbors (n);
         vector<bool> visited(n);

         for(vector<int>& pair:edges){
            neighbors[pair[0]].push_back(pair[1]);
            neighbors[pair[1]].push_back(pair[0]);
        }
        int totalLoops = 0;
        
        for(int i = 0 ;i<n;i++){
            if(!visited[i]){
                totalLoops++;
                check(i,-1,visited,neighbors,totalLoops);
                }
        }
        
        return totalLoops;

    }
    void check(int node, int parent,vector<bool>& v,vector<vector<int>>& friends,int& cycles){
        if(v[node]){
            //cycles++;
            return;
        }
        v[node] = true;

        for(int n : friends[node]){
            if(n == parent)continue; 
            check(n,node,v,friends,cycles);
        }
        
    }
};
