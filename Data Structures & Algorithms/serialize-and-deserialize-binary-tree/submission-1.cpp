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

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        queue<TreeNode*> q;
        string str = "-";
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            if(!cur){
                str+="X-";
            }else{
                str+=to_string(cur->val)+"-";
                q.push(cur->left);
                q.push(cur->right);
             }
            
            q.pop();
        }
        return str;


    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="-X-")return nullptr;
        //for(char c:data)cout<<c;
        queue<TreeNode*> q;
        if(data.size()==1)return nullptr; //nzm da li se i ovde onaj delimiter \0 racuna
        TreeNode* root;
        int i = 1;
    
        string val = "";
        while(data[i] != '-')val+=data[i++];
        
        root = new TreeNode(stoi(val));

        i++;

        q.push(root);
        while(!q.empty()){
            val="";
            TreeNode* parent = q.front();
            while(data[i] != '-')val+=data[i++];
          
            if(val == "X")parent->left = nullptr;
            else {
                TreeNode* newNode = new TreeNode(stoi(val));
                parent->left = newNode;
                q.push(newNode);
                }
           i++;
           val = "";
           while(data[i] != '-')val+=data[i++];
           if(val == "X")parent->right = nullptr;
           else {
                TreeNode* newNode = new TreeNode(stoi(val));
                parent->right = newNode;
                q.push(newNode);
                }
           i++;
           q.pop();
        }
        
        return root;
    }
    
};
