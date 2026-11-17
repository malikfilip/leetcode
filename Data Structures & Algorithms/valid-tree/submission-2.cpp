class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; //bitno da uvek imamo n-1 granu

        vector<vector<int>> neighbors (n); //Adjecent lista cvorova

        vector<bool> visited(n); //Lista obidjenih cvorova, da bi bilo potpuno stablo svi moraju da budu obidjeni tacno 1 dfsom od nekog cvora (ne mora nuzno 0).

        
        for(vector<int>& pair:edges){
            neighbors[pair[0]].push_back(pair[1]);
            neighbors[pair[1]].push_back(pair[0]);
        }
        
        bool res = check(0,-1,visited, neighbors); //Ovde sam uzeo 0 jer cvor broj 0 sigurno postoji, ali teoretski moze bilo koji koji sigurno postoji

        for(bool b: visited){ //Ako je nakon dfsa ostao neki neobidjen cvor, tj postoji cvor iz kog se nije moglo doci povevsi od nekog onda uslov za stablo nije zadovoljen, imamo sume (mozda je ovo redudantno zbor provere u prvoj liniji)
            if(b==false)return false;
        }
        return res;

    }
    bool check(int node, int parent,vector<bool>& v,vector<vector<int>>& friends){
        if(v[node]) return false;
        v[node] = true;

        for(int n : friends[node]){
            if(n == parent)continue; //Posto je bidirekcioni graf ne zelimo da se vracamo odakle smo dosli iako imamo taj node u listi
            if(!check(n,node,v,friends))return false;
        }
        return true;
    }
};
