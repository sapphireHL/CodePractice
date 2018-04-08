/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* pre = nullptr;
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(pre) pre->right = root;
        root->left = pre;
        pre = root;
        inOrder(root->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        inOrder(pRootOfTree);
        TreeNode* p = pRootOfTree;
        while(p->left){
            p = p->left;
        }
        return p;
    }
};
