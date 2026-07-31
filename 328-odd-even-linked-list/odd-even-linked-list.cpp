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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* temp1 = odd;
        ListNode* even = head->next;
        ListNode* temp2 = even;

        ListNode* temp = head->next->next;

        int count = 3;
        while (temp != NULL) {
            if (count % 2 != 0) {
                temp1->next = temp;
                temp1 = temp1->next;
            } else {
                temp2->next = temp;
                temp2 = temp2->next;
            }

            count++;
            temp = temp->next;
        }
        temp2->next=NULL;
        temp1->next = even;
        return odd;
    }
};