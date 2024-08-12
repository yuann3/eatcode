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
        ListNode* current = head;
        int length = 0;
         while (current != nullptr) {
             current = current->next;
             length++;
         }

         if (length == n) {
             ListNode* temp = head->next;
             delete head;
             return temp;
         }

         current = head;
         ListNode* dummy = new ListNode(0);
         ListNode* temp = dummy;

         int steps = length - n;
         for (int i = 0; i < steps; i++) {
             temp->next = current;
             temp = temp->next;
             current = current->next;
         }

         ListNode* nextNode = current->next;
         delete current;
         temp->next = nextNode;
         return dummy->next;
    }
};