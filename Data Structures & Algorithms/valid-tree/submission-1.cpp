class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors (n);
        vector<bool> visited(n);
        //ne moramo da popunjavamo sve nulama neka popunjavamo samo komsijama
        for(vector<int>& pair:edges){
            neighbors[pair[0]].push_back(pair[1]);
            neighbors[pair[1]].push_back(pair[0]);
        }
        
        bool res = check(0,-1,visited, neighbors);
        for(bool b: visited){
            if(b==false)return false;
        }
        return res;

    }
    bool check(int node, int parent,vector<bool>& v,vector<vector<int>>& friends){
        if(v[node]) return false;
        v[node] = true;

        for(int n : friends[node]){
            if(n == parent)continue;
            if(!check(n,node,v,friends))return false;
        }
        return true;
    }
};
