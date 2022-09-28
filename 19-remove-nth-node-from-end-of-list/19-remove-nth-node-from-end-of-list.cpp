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
        ListNode* front = head;
        ListNode* back = NULL;
        
        int count = 0;
        ListNode *tem = head;
        while(tem!=NULL){
            count++;
            tem = tem->next;
        }
        int x = count - n;
        int y = count-n;
        while(x){
            back = front;
            front = front->next;
            x--;
        }
        if((n==1 &&y==0)||n==count){
            head = head->next;
            return head;
        }
        back ->next = front->next;
        front->next = NULL;
        return head;
    }
};