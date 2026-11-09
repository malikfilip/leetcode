/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Pomoc za vektor u ovom ukruzenju:https://leetcode.com/discuss/post/4039616/c-vector-by-bhagyalaxmi-puli-ddme/
        //Pomoz za queue u ovom okruzenju:https://leetcode.com/discuss/post/4044066/c-queue-by-bhagyalaxmi-puli-pnha/
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> bigDaddy;
        if(!root)return bigDaddy;

        while(!q.empty()){
            vector<int> newLevel;
            int levelSize = q.size();
            for(int i = 0;i<levelSize;i++){
                TreeNode* cur = q.front();
               
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                newLevel.push_back(cur->val);

                 q.pop();
            }
            bigDaddy.push_back(newLevel);

        }
        return bigDaddy;



    }
};
