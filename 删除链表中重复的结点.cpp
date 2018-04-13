/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead || !pHead->next) return pHead;
        ListNode* p = pHead, *pre = nullptr;
        
        while(p && p->next && p->val == p->next->val){
            auto pp = p->next;
            while(pp && pp->val == p->val)
                pp = pp->next;
            p = pp;
        }
        pHead = p;
        
        
        while(p && p->next){
            if(p->val != p->next->val){
                pre = p;
                p = p->next;
            }
            //当前与下个节点相同
            else{
                ListNode* pnext = p->next;
                while(pnext && pnext->val == p->val){
                    pnext = pnext->next;
                }
                if(!pre){
                    pre = pnext;
                    pHead = pre;
                }
                else{
                    pre->next = pnext;
                }
                p = pnext;
                if(!p) break;
            }
        }
        return pHead;
    }
};
