class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> window;

         int left = 0;
         int max = 0;

         for (int right = 0;right < s.size();right++){
            while(window.count(s[right])){
                //Ako postoji u windowu mora izbacujemo sve dok ne bude unique
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            int substring = right - left + 1;
            if(substring > max)max = substring;
         }
         return max;
    }
};
