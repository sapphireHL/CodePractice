/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return nullptr;
        RandomListNode* p = pHead;
        
        while(p){
            RandomListNode* node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        
        p = pHead;
        while(p){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        
        //注意拆分
        p = pHead;
        RandomListNode* newhead = p->next, *pnew = newhead;
        p->next = pnew->next;
        p = p->next;
        while(p){
            pnew->next = p->next;
            pnew = pnew->next;
            p->next = pnew->next;
            p = p->next;
        }
        
        return newhead;
    }
};
