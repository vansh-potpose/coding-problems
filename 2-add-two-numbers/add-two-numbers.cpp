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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* t1 = ans;
        int carry=0;

        while(l1 || l2 || carry){
            int a =l1!=NULL?l1->val:0;
            int b =l2!=NULL?l2->val:0;
            
            int sum = a+b+carry;
            int digit = sum%10;
            carry = sum/10;

            t1->next = new ListNode(digit);

            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
            t1= t1->next;

        }
        return ans->next;

    }
};