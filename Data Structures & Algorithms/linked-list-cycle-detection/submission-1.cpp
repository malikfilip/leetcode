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
    bool hasCycle(ListNode* head) {
        if(!head)return false;
        ListNode* turtle,*rabbit;
        turtle = head;
        rabbit = head->next;
        while(rabbit && rabbit->next){ //Ako postoji ciklus ovaj sto skace dva ce kad tad sustici ovog sto skace jedan. Ako nema ciklusa samo ce se izaci iz whilea, samo paziti da while(rabbit) nije dovoljna provera jer rabbit->next->next moze puknuti sigsegv.
            if(rabbit == turtle)return true;
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }
        return false;
    }
};
