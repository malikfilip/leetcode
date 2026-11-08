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
    int maxDepth(TreeNode* root) {
        //Ideja: uvek gledamo dubinu sinova i onaj koji je "dublji" ima jacu tezinu za nase resenje i iz posmatranog nodea vracamo njegovu dubinu +1, i tako sve dok se ne obidjem sam korijen.

        if(!root)return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};
