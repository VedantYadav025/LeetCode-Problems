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
        if (head == nullptr) return nullptr;
        ListNode* current_node = head;
        ListNode* next_node = head->next;
        set<int> st;
        st.insert(current_node->val);
        while (next_node != nullptr){
            if (st.count(next_node->val) > 0){
                current_node->next = next_node->next;
                next_node = next_node->next;
            }
            else{
                st.insert(next_node->val);
                current_node = current_node->next;
                next_node = next_node->next;
            }
        }
        return head;
    }
};