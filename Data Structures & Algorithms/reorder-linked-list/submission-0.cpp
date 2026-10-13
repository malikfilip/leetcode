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
    void reorderList(ListNode* head) {
        //Samo obrnemo listu, i kad imamo obrnutu i originalnu idemo 1 originalna 1 rotirana, kako je ovo medium xd
        ListNode* rotatedHead,*prev,*future;
        ListNode* brzinac,*mid;

        brzinac = mid = head;

        while (brzinac && brzinac->next) {
           
            mid = mid->next;
            brzinac = brzinac->next->next;         
        }
        prev = nullptr;
        rotatedHead = mid;
        
        while(1){
            future = rotatedHead->next;
            rotatedHead->next = prev;
            prev = rotatedHead;
            if(!future)break;
            rotatedHead = future; 

        }
        ListNode* h = head;
        while(rotatedHead){
            ListNode* tmp1 = h->next;
            ListNode* tmp2 = rotatedHead->next;
            if(!tmp1 ||!tmp2)break;
            h->next = rotatedHead;
            h = h->next;
          h->next = tmp1;
            h = h->next;
           // if(h==rotatedHead)break;
            
            rotatedHead = tmp2;
        }   
         
    }
};
