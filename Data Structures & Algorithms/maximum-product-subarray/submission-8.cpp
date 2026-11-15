//Ovo je LLM uradio meni je ovo mnogo tesko da razumem, i razmisljam ozbiljno da odem u pekaru da radim ili da skocim sa mosta.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            
            if (curr < 0) {
               
                swap(maxSoFar, minSoFar);
            }

           
            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);

            
            result = max(result, maxSoFar);
        }

        return result;
    }
};