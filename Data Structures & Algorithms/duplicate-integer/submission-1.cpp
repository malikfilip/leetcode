class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> freq;
        for(int i : nums){
            if(freq.contains(i))return true;
            freq.insert(i);
        }
        return false;
    }
};