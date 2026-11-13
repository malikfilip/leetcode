class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> dp (s.size());
        int max = 1;
        int start = 0;
      
        for (int i = 0;i<s.size();i++){
            int localLen = 1;
            //string pal(1, s[i]); //neki gigachad nacin za pravljene c++ stringova, na etfu od char* nisu imali vremena ovo da pokazu, ovo je too inefficient izgleda :(
            
            int right = i,left = i;
            while(right != s.size()-1 && s[left] == s[right+1] ){
                localLen++;
                
                right++;
                
            }
                left--;
                right++;

            
            
            while(left >=0 && right < s.size() && s[left] == s[right]){
               localLen+=2;
               
                left--;
                right++;
            }
            if(localLen > max){
                max = localLen;
                start = left+1;
            }
           
        }
        
        return s.substr(start, max);
    }
};
