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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* myHead,*head1,*head2,*ret;
        head1 = list1;
        head2 = list2;
        if(!head1)return head2;
        if(!head2)return head1;

        if(head1->val < head2->val){ //Postavljamo glavu nase nove liste na manji pocetni element
            myHead = head1;
            head1 = head1->next;
            ret = list1;
        }
        else{
            myHead = head2;
            head2 = head2->next;
            ret = list2;
        }


        //Dok su oba pointera ziva samo trazimo onaj koji je manji, kada jedan umre ostatak zive liste samo nakacimo na my head

        
        while(head1 && head2){ 
            if(head1->val < head2->val){ //Sledeci element je iz liste 1
                myHead->next = head1;
                head1 = head1->next;
            }else{
                myHead->next = head2;
                head2 = head2->next;
            }
            myHead = myHead->next;
        }
        if(head1)myHead->next = head1;
        if(head2) myHead->next = head2;
      
        return ret;
    }
};
