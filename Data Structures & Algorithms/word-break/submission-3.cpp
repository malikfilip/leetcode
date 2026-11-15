/*class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        string dummy = s;
        return backtrack(dummy,wordDict);
       
    }

    bool backtrack(string& model, vector<string>& wordDict){
        for(string& s : wordDict){
            if(model.substr(0,s.size()) == s){
                string tmp = model.substr(0,s.size());
                model.erase(0,s.size());
                if(model == "" || backtrack(model,wordDict))return true;
                model = tmp + model;

            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.size(), false);
        string dummy = s;
        int ptr = 0;
        return backtrack(dummy,wordDict,ptr,memo);
       
    }

    bool backtrack(string& model, vector<string>& wordDict,int ptr,vector<bool>& mem){
        if(mem[ptr])return false;
        for(string& s : wordDict){
            if(model.substr(ptr,s.size()) == s){
            
                if(ptr+s.size() == model.size() || backtrack(model,wordDict,ptr+s.size(),mem))return true;
                
            }
        }
        mem[ptr] = true;
        return false;
    }
};