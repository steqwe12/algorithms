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
        if(head==nullptr) return nullptr;

        std::unordered_map<Node*, int> keys1Reverse;
        //std::unordered_map<int, Node*> keys1;
        std::unordered_map<int, Node*> list1Randoms; 
       // std::unordered_map<Node*, int> keys2Reverse;
        std::unordered_map<int, Node*> keys2; 
        int i=1;

        while(head){
            //keys1[i]=head;
            keys1Reverse[head]=i;
            list1Randoms[i]=head->random;

            Node *node = new Node(head->val);
            keys2[i]=node;
            //keys2Reverse[node]=i;

            i++;
            head=head->next;
        }

        for (int j=1;j<i;j++){
            keys2[j]->next = keys2[j+1];
            keys2[j]->random = keys2[keys1Reverse[list1Randoms[j]]];
        }
        return keys2[1];


    }
};