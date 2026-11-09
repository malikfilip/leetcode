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
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k<0)return -1;
        vector<int> dfsVec;
        //hardcode idea vrv nije tacna, samo uradimo dfs i ona skinemo k elemenata
        inOrder(root,dfsVec);
        if(k<=dfsVec.size()+1)return dfsVec[k-1];
        else return -1;
    }
    void inOrder(TreeNode* root, vector<int>& v){ //bitno da je po referenci retarde
        if(root->left)inOrder(root->left,v);
        v.push_back(root->val);
        if(root->right)inOrder(root->right,v);

        
    }
};
