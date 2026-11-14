class Solution {
public:
    int numDecodings(string s) {
        //Mnogo dobro objasnjenje nikada ne bih skapirao ovo sam jebiga:https://youtu.be/W4rYz-kd-cY?si=r4RQOAnI4pBLx7FN
        vector<int> dp(s.length()+1); //dp[0] je koliko interpretacija ima prazan string, dp[1] koliko string od 1 karaktera
        
        if(s[0]=='0')return 0; //budjavi edge case

        dp[0] = dp[1] = 1;
        for(int i = 2;i<=s.length();i++){

            if(s[i-1]=='0' && s[i-2] != '1' && s[i-2] != '2')return 0; //budjavi edge case opet jer 0  pravi problem

            if(s[i-1] == '0'){
                dp[i] = dp[i-2];
                continue;
            }else{
                dp[i] = dp[i-1];
                string str = s.substr(i - 2, 2);
                int num = stoi(str);
                if(num >=10 && num<=26)dp[i]+=dp[i-2];
            }
            
        }
        return dp[s.length()];
    }
};
