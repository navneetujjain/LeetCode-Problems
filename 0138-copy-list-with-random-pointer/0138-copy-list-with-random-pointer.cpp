/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node* , Node*> mpp;
        Node* ptr = head;
        while(ptr){
          mpp[ptr] = new Node(ptr -> val);
          ptr = ptr -> next;
        }
        ptr = head;
        while(ptr){
          mpp[ptr] -> next = mpp[ptr -> next];
          mpp[ptr] -> random = mpp[ptr -> random];
          ptr = ptr -> next;
        }
        return mpp[head];

    }
};