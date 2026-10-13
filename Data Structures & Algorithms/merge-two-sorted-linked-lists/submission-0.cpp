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
        if(head1->val < head2->val){
            myHead = head1;
            head1 = head1->next;
            ret = list1;
        }
        else{
            myHead = head2;
            head2 = head2->next;
            ret = list2;
        }
        while(head1 || head2){
            if(!head2 || head1 && head1->val < head2->val){ //Sledeci element je iz liste 1
                myHead->next = head1;
                head1 = head1->next;
            }else{
                myHead->next = head2;
                head2 = head2->next;
            }
            myHead = myHead->next;
        }
      
        return ret;
    }
};
