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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)return true;
        if(!root)return false;
        if(isEqual(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot))return true;
        return false;

       
    }
    bool isEqual(TreeNode* n1,TreeNode* n2){
        if(!n1 && !n2)return true;
        if(!n1 || !n2)return false;
        return (n1->val == n2->val && isEqual(n1->left,n2->left) && isEqual(n1->right,n2->right) );
    }
};
