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
        if(!pHead) return nullptr;
        ListNode* newhead = new ListNode(0);//dummy节点
        newhead->next = pHead;
        ListNode* p = pHead, *pre = newhead;
        while(p && p->next){
            if(p->val == p->next->val){
                int num = p->val;
                while(p && p->val == num) p = p->next;
                pre->next = p;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return newhead->next;
    }
};
