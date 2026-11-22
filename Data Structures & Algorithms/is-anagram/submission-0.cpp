class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        unordered_map <char,int> m1,m2;
        for(int i = 0 ; i<s.size();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        
        if(m1.size() != m2.size())return false;
        
        for(pair<int,int> p : m1){
            if (m2[p.first] != p.second)return false;
            
        }
        return true;

    }
};
