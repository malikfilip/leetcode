class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //moramo sam da guglam ovo, posle svega ovoga i dalje nisam skapirao kako se radi ovo

        int currentMax = 0;
        unordered_set<int> freq;
        for(const int& num : nums){freq.insert(num);}
       
        for(const int& num : freq){
            if(freq.find(num-1) !=freq.end())continue; 
            int myStreak = 1;
            int cur = num;
            while(freq.contains(cur+1)){myStreak++;cur++;}
            if(myStreak > currentMax)currentMax = myStreak;

        }
        return currentMax;
    }
};
