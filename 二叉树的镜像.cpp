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
    void Mirror(TreeNode *pRoot) {
        if(pRoot){
            Mirror(pRoot->left);
            Mirror(pRoot->right);
            swap(pRoot->left, pRoot->right);
        }
    }
};
//后序遍历
