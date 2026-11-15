class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int maxi;
        int mini;
        int ret;
        
        maxi = nums[0];
        mini = nums[0];
        ret = nums[0];
        for(int i = 1 ;i<nums.size();i++){
            int tempMax = max({nums[i], maxi * nums[i], mini * nums[i]});
            mini = min({nums[i], maxi * nums[i], mini * nums[i]});
            maxi = tempMax;

            ret = max(ret, maxi);
            
        }
        return ret;
    }
};
