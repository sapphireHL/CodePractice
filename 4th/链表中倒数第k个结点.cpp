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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead) return nullptr;
        auto fast = pListHead, slow = pListHead;
        for(int i=0; i<k-1; ++i){
            if(!fast) return nullptr;
            fast = fast->next;
        }
        //这里要判断是否为空
        if(!fast) return nullptr;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
