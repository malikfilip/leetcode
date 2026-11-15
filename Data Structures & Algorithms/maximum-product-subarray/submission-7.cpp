class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // 1. ŠTA SE DEŠI AKO JE BROJ MANJI OD 0?
            if (curr < 0) {
                // Negativan broj obrće sve naopačke! 
                // Ono što je bilo minimum postaje maksimum, i obrnuto.
                swap(maxSoFar, minSoFar);
            }

            // 2. ŠTA SE DEŠAVA DALJE (i za negativne posle zamene, i za pozitivne)?
            // Pozitivan broj samo množi i raste/pada normalno, bez ikakvog prevrata.
            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);

            // Pamtim najveći rezultat do sada
            result = max(result, maxSoFar);
        }

        return result;
    }
};