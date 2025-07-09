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
    ListNode* addTwoNumbersHelper(ListNode* &l1, ListNode* &l2) {

        ListNode* ans = new ListNode(-1);
        ListNode* ansIterator = ans;

        int carry = 0;

        while(l1 || l2 || carry){
            
            int a = l1 != NULL ? l1->val : 0;
            int b = l2 != NULL ? l2->val : 0;

            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ansIterator->next = new ListNode(digit); 

            
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }  
            ansIterator = ansIterator->next;
        }
        return ans;


    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

         ListNode* ans = addTwoNumbersHelper(l1, l2);
         return ans->next;
    }
};