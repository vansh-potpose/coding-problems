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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(val);
        dummy->next=head;
        while(head!=NULL && head->next!=NULL){
            if(dummy->val==head->next->val){
                head->next=head->next->next;
            }else{
                head=head->next;
            }
        }   
        if(dummy->next!=NULL && dummy->next->val==val){
            return dummy->next->next;
        }
        return dummy->next;
    }
};