/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//用栈，空间O（n+m），时间O（n+m）
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> stk1, stk2;
        ListNode*p1 = pHead1, *p2 = pHead2;
        while(p1){
            stk1.push(p1);
            p1 = p1->next;
        }
        while(p2){
            stk2.push(p2);
            p2 = p2->next;
        }
        ListNode* common = nullptr;
        while(!stk1.empty() && !stk2.empty()){
            auto tmp1 = stk1.top(), tmp2 = stk2.top();
            stk1.pop();
            stk2.pop();
            if(tmp1 == tmp2)
                common = tmp1;
            else{
                break;
            }
        }
        return common;
    }
};

//利用长度，空间O（1），时间O（m+n）
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode*p1 = pHead1, *p2 = pHead2;
        int len1 = 0, len2 = 0;
        while(p1){
            len1++;
            p1 = p1->next;
        }
        while(p2){
            len2++;
            p2 = p2->next;
        }
        p1 = pHead1, p2 = pHead2;
        if(len1 > len2){
            for(int i = 0; i < len1 - len2; i++)
                p1 = p1->next;
        }
        else if(len2 > len1){
            for(int i = 0; i < len2 - len1; i++)
                p2 = p2->next;
        }
        while(p1 && p2){
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};
