class Solution {
public:

    
    int characterReplacement(string s, int k) {
        
        int windowLen; //Pomocna promenjiva za duzinu prozora
        int maxLen = 0; //ono sto returnujemo
        int mapMax; //Pomocna promenjiva u koju stavljamo najvecu pronadjenu vrednost u mapi
        int left = 0;
        unordered_map<char, int> m; //Mapa koja cuva pojavljivanje slova u prozoru
        
         for (int right = 0;right < s.size();right++){
            
             m[s[right]]++;
            
            windowLen = right-left + 1;
            mapMax = 0;
            for (auto& [key, val] : m) { //Trazimo max val u mapi, u cpp ne znam moze li jednostavnije
              
                mapMax = max(mapMax,val);
            }
            if(windowLen - mapMax <= k){ //Window je legit, ovo nisam skapirao i zato sam se mucio.
               
        
                maxLen = max(windowLen,maxLen);

            }else{
                while(windowLen - mapMax > k){
                    if(--m[s[left]] == 0)m.erase(s[left]);
                    left++;
                    windowLen = right-left + 1;
                    mapMax = 0;
                    for (auto& [key, val] : m) { //Ovo raznosi vremensku slozenost ali sta cemo.
                        mapMax = max(mapMax,val);
                    }
                }
                
            }

            
            
         }
         return maxLen;
       
    }
};
