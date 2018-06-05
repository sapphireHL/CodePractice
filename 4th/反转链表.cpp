/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/


//递归
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return nullptr;
        if(!pHead->next) return pHead;//这里不可少，否则整个函数返回null
        ListNode* root = ReverseList(pHead->next);
        if(pHead->next){
            pHead->next->next = pHead;
            pHead->next = nullptr;
        }
        return root;
    }
};




//迭代
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return nullptr;
        if(!pHead->next) return pHead;
        ListNode* p = pHead, *newhead = nullptr, *next = p->next;
        while(p){
            next = p->next;
            p->next = newhead;
            newhead = p;
            p = next;
        }
        return newhead;
    }
};
