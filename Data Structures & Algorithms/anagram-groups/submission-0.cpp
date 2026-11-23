class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (string s: strs){
            vector<int> freq (26,0); //Kazu da su sve mala slova pa malo radimo na bulgari
            for(char c: s){
                freq[c-'a']++;
            }
            string key = ""; //Da bismo sve anagreme grupisali koristimo kljuc X|X|X gde je X broj pojavljivanja i tog elemnta a | delimiter
            for(int i = 0;i<26;i++){
                key+= to_string(freq[i]);
                key+= '|';
            }
            if(m.find(key) == m.end()){
                vector<string> s;
                m[key] = s;
                
            }
            m[key].push_back(s);

        }
        vector<vector<string>> ret;
        for(auto& p : m){
            ret.push_back(p.second);
        }
        return ret;
    }
};
