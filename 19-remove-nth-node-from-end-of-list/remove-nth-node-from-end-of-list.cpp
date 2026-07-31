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
        if(head->next==NULL){
            return NULL;
        }
        ListNode*temp1=head;
        int size=0;
        while(temp1!=NULL){
            size++;
            temp1=temp1->next;
        }
         if(size == n){          
            return head->next;
        }

        int diff=size-n-1;
        int count=0;
        ListNode*temp2=head;;

        while(count<diff){
           
           count++;
           temp2=temp2->next;
        }

        ListNode*newNode=temp2->next->next;
        temp2->next=newNode;

        return head;
    }
};