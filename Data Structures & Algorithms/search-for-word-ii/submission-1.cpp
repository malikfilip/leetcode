class Solution {
public:

    struct Node{
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = createTrie(words);
        vector<string> res;

        for(int i = 0;i <board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                
                dfs(root,i,j,board,"",res);
            }
        }
        return res;
    }

    Node* createTrie(vector<string>& w){
        Node* root = new Node();
        for(string str: w){
            Node* cur = root;
            for(char c: str){
                if(!cur->children[c-'a'])cur->children[c-'a'] = new Node();
                cur = cur->children[c-'a'];
            }
            cur->isEnd = true;
        }
        return root;
    }

    void dfs(Node* trie,int i,int j,vector<vector<char>>& b,string word,vector<string>& res){
        if(b[i][j] == '#')return;
        
        Node* kid = trie->children[b[i][j]-'a'];
        if(kid){
          
            char val = b[i][j];
            word+=val;
            if(kid->isEnd && (find(res.begin(), res.end(), word) == res.end()))res.push_back(word);
            b[i][j] = '#';
            if(i != 0)  dfs(kid,i-1,j,b,word,res);
            if(j != 0)  dfs(kid,i,j-1,b,word,res);
            if(i != b.size()-1)  dfs(kid,i+1,j,b,word,res);
            if(j != b[0].size()-1)  dfs(kid,i,j+1,b,word,res);
            b[i][j] = val;
 
            
        }
    
    }
};
