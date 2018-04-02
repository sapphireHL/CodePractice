/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* p1 = pHead1, *p2 = pHead2, *res = new ListNode(0), *p = res;
        while(p1 && p2){
            if(p1->val <= p2->val){
                p->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            else{
                p->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1)
            p->next = p1;
        else if(p2)
            p->next = p2;
        return res->next;
    }
};
