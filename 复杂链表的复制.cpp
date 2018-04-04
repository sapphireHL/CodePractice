/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

//用哈希表存储旧节点和新节点的对应关系，空间O（n）
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* p = pHead, *newhead = new RandomListNode(0), *p2 = newhead;
        //复制next节点
        while(p){
            p2->next = new RandomListNode(p->label);
            mp[p] = p2->next;
            p2 = p2->next;
            p = p->next;
        }
        //复制random节点
        p = pHead;
        while(p){
            if(p->random){
                mp[p]->random = mp[p->random];
            }
            p = p->next;
        }
        return newhead->next;
    }
};


//将新节点放在原节点的后面，保持新旧对应关系，空间O（1）
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return nullptr;
        RandomListNode* p = pHead, *newhead, *p2;
        //将新节点放在原节点的后面
        while(p){
            RandomListNode* node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }
        //复制random节点
        p = pHead;
        while(p){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        //拆分2个链表
        p = pHead;
        if(p){
            newhead = p2 = p->next;
            p->next = p2->next;
            p = p->next;
        }
        while(p){
            p2->next = p->next;
            p2 = p2->next;
            p->next = p2->next;
            p = p->next;
        }
        return newhead;
    }
};
