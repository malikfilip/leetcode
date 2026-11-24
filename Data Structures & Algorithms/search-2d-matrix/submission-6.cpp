class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0 ; i < matrix.size(); i++){
            if(target>= matrix[i][0] && target <=matrix[i][matrix[0].size()-1]){
                int left = 0;
                int right = matrix[0].size()-1;
                int mid = (left + right) / 2;
                while(left <= right){
                    if(target == matrix[i][mid])return true;
                    if(target < matrix[i][mid]){right = mid - 1;}
                    else{left = mid + 1;}
                    mid = (left + right) / 2;
                }
                return false;
            }
        }
        return false;
    }
};
