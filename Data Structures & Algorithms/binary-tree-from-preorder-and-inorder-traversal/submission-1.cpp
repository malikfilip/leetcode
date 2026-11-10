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
      //Mapa za inorder gde je key node val a vrednost je indeks u inorder nizu. Kada posmatramo inorder niz ovi levo od njega ce biti levo podstablo ovi desno ce biti desno, to je bitno da dok idemo kroz preorder znamo da li je sledeci node levi ili desni
     
    unordered_map<int, int> indexMap; 



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
            for(int i = 0 ;i<inorder.size();i++){
                indexMap.insert({inorder[i], i}); //U mapu dodajemo (vrednost nodea,index u inorderu)
            }
        int preorderIndex = 0; //Node od koga krecemo da cementiramo

        return buildSubtree(0,inorder.size()-1,preorder,preorderIndex);
    }

    TreeNode* buildSubtree(int inStart,int inEnd,vector<int>& pre,int& cnt){
      
         
        if(inStart > inEnd)return nullptr; //Pogledati video tutorial zasto je ovo razlog za null, kada se boundsi obrnu ispada da obilazimo decu lista a ona ne postoje.
        TreeNode* newNode = new TreeNode(pre[cnt++]); //Za svaki poziv pravi node



        int inorderIndex = indexMap[newNode->val];
        newNode->left = buildSubtree(inStart,inorderIndex-1,pre,cnt); //Za levo podstablu ulazimo u levu stranu preordera u odnosu na tekuci node
        newNode->right = buildSubtree(inorderIndex+1,inEnd,pre,cnt); //Isto tako i za desno
        return newNode;

        
          
        
        
        
    }

};
