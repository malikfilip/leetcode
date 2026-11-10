class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> window;
        backtrack(nums,ret,window,target,0);
        return ret;
        
    }
    void backtrack(vector<int>& candidates,vector<vector<int>>& res,vector<int>& path,int left,int start){
        if (left == 0){
            res.push_back(path);
        }
        if(left < 0)return;
        for(int i = start;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backtrack(candidates,res,path,left-candidates[i],i);
            path.pop_back(); //skloni onaj raniji
        }
    }
};
