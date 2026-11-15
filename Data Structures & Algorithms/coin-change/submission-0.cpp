class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)return 0;

        vector<int> dp (amount+1);
        dp[0] = 0; //ovo ne mora da stoji ali nagalsavamo da mi ovo zelimo a ne da je stl to odradio za nas
        for(int i = 1;i<=amount;i++){ //Koliko sklapamo

            for(int c: coins){ //Gledamo za svaku novcanicu koliko je optimalna
                if(i-c < 0)continue;
                if(i-c == 0){
                    dp[i] = 1;
                    break;
                }
                if(dp[i-c]){
                    if(dp[i])
                    {
                         dp[i] = min(dp[i-c]+1,dp[i]);
                    }else{
                        dp[i]= dp[i-c]+1;
                    }
                    
                }
               
                
                
                
                    
                
            }
            
        }
        return dp[amount] ?  dp[amount] : -1;
    }
};
