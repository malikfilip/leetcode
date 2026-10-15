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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* turtle,*rabbit,*prev;
        turtle = rabbit = head;
        if(!head)return nullptr;
        for(int i = 0;i < n;i++){
            if(!rabbit)return nullptr; //Ako smo OVDE izleteli van scopea onda je n>duzine liste
            rabbit = rabbit->next; //Ovaj potencijalno moze da uleti u null
            
        }
        while(rabbit){
            prev = turtle; //Posto cemo morati da brisemo turela moramo da bazimo da imamo pokazivac na prev
            turtle = turtle->next;
            rabbit = rabbit->next;
        }
        if(turtle == head){
            head = turtle->next;
        }else{
            prev->next = turtle->next;
        }
        return head;
    }
};
