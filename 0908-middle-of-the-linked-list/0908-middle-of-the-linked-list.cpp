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
    
    int length(ListNode* head){
        int length = 0;
        while(head != nullptr){
            length++;
            head = head->next;
        }
        return length;
        // O(n)
    }

    ListNode* middleNode(ListNode* head) {
       int len = length(head);
       if (len % 2 == 0){
           for(int i = 0; i < (len/2) ; i++){
               head = head->next;
           }
           return head;
       } 
       else{
           for(int i = 0; i < (len/2) ; i++){
               head = head->next;
           }
           return head;
       }
       return head;
    }
};