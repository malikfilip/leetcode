/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //Unordered set: https://leetcode.com/discuss/post/4056081/unorderd-set-by-bhagyalaxmi-puli-phx1/
        
        if(!node)return nullptr;
        
        unordered_set<Node*> visited;
        unordered_map<Node*,Node*> pairs;

        buildMap(node,pairs);
        makeClone(node,pairs,visited);

        return pairs[node];

        

    }
    void buildMap(Node* oldNode,unordered_map<Node*,Node*>& p){
        if(p.find(oldNode) != p.end())return; //vec smo obisli ovaj node ne zelimo da nas rekurzija izede
        Node* newNode = new Node(oldNode->val);
        p[oldNode] = newNode;
        for(Node* n: oldNode->neighbors){
            buildMap(n,p);
        }
    }
    void makeClone(Node* node,unordered_map<Node*,Node*>& p,unordered_set<Node*>& v){
        if(v.find(node) != v.end())return;
        v.insert(node);
        for(Node* neighbor : node->neighbors){
            p[node]->neighbors.push_back(p[neighbor]);
            makeClone(neighbor,p,v);
        }
        
    }
};
