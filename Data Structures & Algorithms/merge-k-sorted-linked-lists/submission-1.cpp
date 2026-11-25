/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        struct CompareNode {
             bool operator()(const ListNode* a, const ListNode* b) const {
                    return a->val > b->val; //Ako je ovo tru onda ce znaciti da je prvi argument sin, ako je false onda je drugi
             }
             };

        priority_queue<ListNode*,vector<ListNode*>,CompareNode> minHeap;
        ListNode* head,*curr;
        head=curr=nullptr;

        for(int i = 0;i<lists.size();i++){
                if(!lists[i])continue; // cmarevi podmecu prazne liste u test primere
                minHeap.push(lists[i]);
 
        }
        while(!minHeap.empty()){
            if(!head){head = minHeap.top();curr = head;}
            else{
                curr->next = minHeap.top();
                curr = curr->next;
            }
            if(minHeap.top()->next)minHeap.push(minHeap.top()->next);
            minHeap.pop();
        }
        if(curr)curr->next = nullptr;
        return head;
    }
};
