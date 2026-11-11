class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n);
        //Tabulacija(ovo resenje) u dinamickom programiranju, bottom up gradimo krajnje resenje prvo racunajuci manje delove veceg resenja
        
        //Postoji i memorizacija koja je top down, kreces od vrha i spustas se dole ali kesiras (pamtis) ako si neki manji deo problema vec resio da se ne bi cimao da ga radis opet (npr u fibonacuje imamo 2 puta poziv fibonacija za isti broj, pa da ne bi radili 2 puta koristimo mapu.)
        
        if (n == 1)return 1;
        if ( n== 2)return 2;
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n-1];
    }
};
