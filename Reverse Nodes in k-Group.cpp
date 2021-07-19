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
    int bp = 0,kj = 0;
    ListNode* reverse(ListNode* head, int k)
    {
        if(kj==bp){
            return head;
        }
        // base case
        if (!head)
            return NULL;
        kj+=1;
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;

        /*reverse first k nodes of the linked list */
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        /* next is now a pointer to (k+1)th node
        Recursively call for the list starting from current.
        And make rest of the list as next of first node */
        if (next != NULL)
            head->next = reverse(next, k);

        /* prev is new head of the input list */
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;ListNode* pt=head;
        while(pt!=NULL){
            pt=pt->next;len+=1;
        }
        bp = len/k;
        return reverse(head,k);
    }
};