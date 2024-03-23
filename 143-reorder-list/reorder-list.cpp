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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        stack<ListNode*> st;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* counter = slow;

        if(fast != NULL) counter = slow -> next;

        while(counter != NULL){
            st.push(counter);
            counter = counter -> next;
        }

        fast = head;

        while(st.size()){
            counter = fast -> next;
            fast -> next = st.top();
            st.top() -> next = counter;
            fast = counter;
            st.pop();
        }

        slow -> next = NULL;


    }
};