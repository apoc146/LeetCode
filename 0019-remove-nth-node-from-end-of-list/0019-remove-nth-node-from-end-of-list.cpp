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
    int count=0;
    ListNode* prev=NULL;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
                    return head;
                }

                head->next = removeNthFromEnd(head->next, n);
                count++;

                if (count == n) {
                    ListNode* nextNode = head->next;
                    delete head; 
                    return nextNode; 
                }

                return head;
        
    }
};