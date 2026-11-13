class Solution {
public:
    int rob(vector<int>& nums) {

        

        vector<int> dp1 (nums.size()); //dp1 krece od prve i ignorise poslednju
        vector<int> dp2 (nums.size()); //dp2 krece od druge, ignorise prvu ali sme da ukljuci poslednju
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
       
        
        
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1],nums[2]);

        

        for(int i = 2;i<nums.size();i++){
            
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]); 
            
            if(i!=nums.size()-1)dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i+1]);
        }
        return max(dp1[nums.size()-2],dp2[nums.size()-2]);

        
    }
};
