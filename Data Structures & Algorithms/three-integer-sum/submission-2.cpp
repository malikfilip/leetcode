class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            int left = i+1;
            int right = nums.size()-1;
            if(nums[i]>0)break;
            while(left < right){ //Veoma gadn zadatak.
                int sum = nums[left] + nums[right] + nums[i];
                if(sum < 0){
                    left++;
                    continue;
                }
                if(sum > 0){
                    right--;
                    continue;
                }
                ret.push_back({nums[left],nums[right],nums[i]});
                
                while(left < right && nums[left] == nums[left+1]){left++;}
                left++;
                right--;
            }
        }
        return ret;
    }
};

