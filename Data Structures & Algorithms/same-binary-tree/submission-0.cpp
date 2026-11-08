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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true; //Ako su oba suplja to je ok !

        if(p && q){ //Ako oba postoje proveri jesu li ista, i ako jesu idi spustaj se dalje
            if(p->val != q->val)return false;

            if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right)) return false;

            return true;
        }
        return false; //Ako je kombinacija da je jedan nullptr a drugi postoji odma je false i izbegavao nullptr exception
        


    } 
        
};
