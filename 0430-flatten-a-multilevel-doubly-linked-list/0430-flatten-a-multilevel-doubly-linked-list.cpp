/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void PushNodes(Node* dummy,vector<Node*> &v){
        if(dummy==nullptr) return ;
        v.push_back(dummy);
        PushNodes(dummy->child,v);
        PushNodes(dummy->next,v);
    }
    Node* flatten(Node* head) {
        vector<Node*> v;
        PushNodes(head,v);
        int length=v.size();
        if(length==0) return nullptr;

        v[0]->child=nullptr;v[0]->prev=nullptr;
        if(length>1) v[0]->next=v[1];

        v[length-1]->child=nullptr;v[length-1]->next=nullptr;
        if(length>1) v[length-1]->prev=v[length-2];

        for(int i=1;i<length-1;i++){
            v[i]->child=nullptr;v[i]->prev=v[i-1];v[i]->next=v[i+1];
        }
        return v[0];
    }
};