class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq (nums.size()+1); //vektori koji brojevi se pojavljuju i puta
        unordered_map<int,int> numFreqMap;
        for(int i : nums){
            numFreqMap[i]++;
        }
        for(auto& p:numFreqMap){
            freq[p.second].push_back(p.first);
        }
        vector<int>ret;
        int i = 0;
        while(k>0 && i < freq.size()){
            if(!freq[freq.size()-1-i].empty()){
                for( const auto&  x : freq[freq.size()-1-i]){
                    ret.push_back(x);
                    if(--k == 0)return ret;
                }
            }
            i++;
        }
        return ret;
    }
};
