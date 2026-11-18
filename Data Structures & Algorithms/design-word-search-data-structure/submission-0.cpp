class WordDictionary {
public:
    struct Node {
        Node* children[52] = {nullptr}; //Sada imamo i mala i velika slova !
        bool isEnd = false;
        
    };
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char c: word){
            int index = c-'A'< 26 ? c-'A' : c-'A' - 6; //ova sestica je zbog onih znakova kojih ima 6 izmedju malih i velikih slova u asiju
            if(!cur->children[index])cur->children[index] = new Node();
            cur = cur->children[index];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        
        return dfs(root,0,word);
            
    }
    bool dfs(Node* cur, int i, const string& word) {
        if (!cur) return false;
        if (i == word.size()) return cur->isEnd; 

        if (word[i] == '.') {
            for (Node* next : cur->children) {
                if (next && dfs(next, i + 1, word)) return true; // Ako jedna grana propadne, petlja prirodno ide na sledeću!
            }
            return false;
        } else {
            int idx = word[i] - 'A' < 26 ? word[i] - 'A' : word[i] - 'A' - 6;
            return dfs(cur->children[idx], i + 1, word);
        }
    }
};
