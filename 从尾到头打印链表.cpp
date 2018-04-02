/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> res;
    void dfs(ListNode* root){
        if(root){
            dfs(root->next);
            res.push_back(root->val);
        }
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        dfs(head);
        return res;
    }
};
