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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-101);
        dummy->next=head;

        while(head!=NULL && head->next!=NULL){
            if(head->next->val==head->val){
                head->next=head->next->next;
            }else{
                head=head->next;
            }
        }
        return dummy->next;
    }
};