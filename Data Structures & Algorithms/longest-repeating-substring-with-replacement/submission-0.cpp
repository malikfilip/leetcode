class Solution {
public:

    
    int characterReplacement(string s, int k) {
        
        int windowLen;
        int maxLen = 0;
        int mapMax;
        int left = 0;
        unordered_map<char, int> m;
        
         for (int right = 0;right < s.size();right++){
            if(m.count(s[right])){
                m[s[right]]++;
            }else{
                m.insert({s[right],1});
            }
            windowLen = right-left + 1;
            mapMax = 0;
            for (auto& [key, val] : m) {
                if(val > mapMax)mapMax = val;
            }
            if(windowLen - mapMax <= k){
                //Window je legit
                if(windowLen > maxLen)maxLen = windowLen;

            }else{
                while(windowLen - mapMax > k){
                    if(--m[s[left]] == 0)m.erase(s[left]);
                    left++;
                    windowLen = right-left + 1;
                    mapMax = 0;
                    for (auto& [key, val] : m) {
                        if(val > mapMax)mapMax = val;
                    }
                }
                
            }

            
            
         }
         return maxLen;
       
    }
};
