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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCA = root;
        if(p->val < root->val && q->val < root->val){
            LCA = lowestCommonAncestor(root->left,p,q);
        }else if(p->val > root->val && q->val > root->val){
            LCA = lowestCommonAncestor(root->right,p,q);
        }
        return LCA;
    }
};
