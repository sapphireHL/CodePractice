//迭代版
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* cur = pHead, *newHead = nullptr;
        if(!cur)
            return nullptr;
        while(pHead){
            cur = pHead->next;
            pHead->next = newHead;
            newHead = pHead;
            pHead = cur;
        }
        return newHead;
    }
};

//递归版
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* newHead = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return newHead;
    }
};
