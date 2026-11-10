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
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int bestPath = INT_MIN;
        getBestPath(root,bestPath);
        return bestPath;
    }
    int getBestPath(TreeNode* node, int& maxVar){
        if(!node)return 0;
        int lMax = getBestPath(node->left,maxVar);
        int rMax = getBestPath(node->right,maxVar);
        if(node->val+rMax+lMax > maxVar)maxVar = node->val+rMax+lMax;
        int optimalPath = (node->val + lMax > node->val + rMax) ? node->val + lMax : node->val + rMax;
        return optimalPath > 0 ? optimalPath : 0;
    }
};
