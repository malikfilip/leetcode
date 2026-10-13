class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right)  / 2;

        while(left != right){
            
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{right = mid;}
            mid = (left + right)  / 2;
        }
        return nums[left];
    }
};
