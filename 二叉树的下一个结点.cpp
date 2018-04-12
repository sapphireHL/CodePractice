/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* pre, *res;
    void inorder(TreeLinkNode* root, TreeLinkNode* target){
        if(root){
            inorder(root->left, target);
            if(pre == target) res = root;
            pre = root;
            inorder(root->right, target);
        }
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode) return nullptr;
        TreeLinkNode* p = pNode;
        while(p->next){
            p = p->next;
        }
        pre = res = nullptr;
        inorder(p, pNode);
        return res;
    }
};
