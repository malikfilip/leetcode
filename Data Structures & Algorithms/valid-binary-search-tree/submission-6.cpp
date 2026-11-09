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
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
       
        return bounds(root,INT_MIN,INT_MAX);

    }
    bool bounds(TreeNode* n,int min,int max){
        if(!n)return true;
        if(n->val <= min || n->val >= max) return false;
        return bounds(n->left,min,n->val) && bounds(n->right,n->val,max);
    }
   

};
