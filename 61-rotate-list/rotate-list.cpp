class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* prev = new ListNode(-1);
        prev->next = head;

        ListNode* node = NULL;
        ListNode* temp = head;

        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if (k == 0)
            return head;

        temp = head;
        int cnt = 0;

        while (temp != NULL) {

            if (temp->next != NULL) {
                node = temp;
                temp = temp->next;
            } 
            else {
                temp->next = prev->next;
                head = temp;
                prev->next = head;
                node->next = NULL;
                cnt++;

                if (cnt == k)
                    break;

                temp = head;
                node = NULL;
            }
        }

        return head;
    }
};