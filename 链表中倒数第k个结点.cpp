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
        ListNode* p = pListHead;
        int length = 0;
        while(p){
            length++;
            p = p->next;
        }
        if(k > length)
            return nullptr;
        p = pListHead;
        int cnt = 0;
        while(cnt < (length-k)){
            cnt++;
            p = p->next;
        }
        return p;
    }
};
