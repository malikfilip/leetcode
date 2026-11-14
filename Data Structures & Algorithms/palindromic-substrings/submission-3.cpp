class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        vector<vector<bool>> dp(size, vector<bool>(size, false)); //FORA KAKO NAPRAVITI MATRICU !

        //popunjavamo glavnu dijagonalu
        for(int i = 0; i < size;i++){
            dp[i][i] = true;
        }
        //popunjavamo prvu sporednu dijagonalu pre nego sto krene iteracija

        for(int i = 0;i<size-1;i++){ //poslednji se ispituje u ono [i+1]
            if(s[i] == s[i+1])dp[i][i+1] = true;

        }
        for (int l = 0; l < size-2;l++){ //broj sporednih dijagonala koje
            for(int i = 0;i < size - 2 - l;i++){
                int j = 2 + l + i;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }
            }

        }
        int ret = 0;
        for (const auto& row : dp) { // GEMINI optimizacija 
            ret += std::count(row.begin(), row.end(), true);
        }
        return ret;
    }
    
};
