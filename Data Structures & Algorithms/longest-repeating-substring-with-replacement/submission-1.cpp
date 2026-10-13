class Solution {
public:

    
    int characterReplacement(string s, int k) {
        
        int windowLen;
        int maxLen = 0;
        int mapMax;
        int left = 0;
        unordered_map<char, int> m;
        
         for (int right = 0;right < s.size();right++){
            
             m[s[right]]++;
            
            windowLen = right-left + 1;
            mapMax = 0;
            for (auto& [key, val] : m) {
              
                mapMax = max(mapMax,val);
            }
            if(windowLen - mapMax <= k){
                //Window je legit
        
                maxLen = max(windowLen,maxLen);

            }else{
                while(windowLen - mapMax > k){
                    if(--m[s[left]] == 0)m.erase(s[left]);
                    left++;
                    windowLen = right-left + 1;
                    mapMax = 0;
                    for (auto& [key, val] : m) {
                        mapMax = max(mapMax,val);
                    }
                }
                
            }

            
            
         }
         return maxLen;
       
    }
};
