class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left (nums.size());
        vector<int> right (nums.size());

        left[0] = 1;
        left[1] = nums[0]; //imamo bar 2 elementa tkd nas boli rac
        right[nums.size()-1] = 1;
        right[nums.size()-2] = nums[nums.size()-1];

        for(int i = 2; i < nums.size();i++){
            left[i] = left[i-1]*nums[i-1];
            right[nums.size()-1-i] = right[nums.size()-i]*nums[nums.size()-i];
        }
        for(int i = 0; i < left.size();i++){
            left[i]*=right[i];
        }
        return left;
    }
};
