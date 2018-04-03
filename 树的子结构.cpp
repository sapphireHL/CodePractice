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
    bool isTree1HasTree2(TreeNode* p1, TreeNode* p2){
        if(!p2)
            return true;
        if(!p1)
            return false;
        if(p1->val != p2->val)
            return false;
        return isTree1HasTree2(p1->left, p2->left) && isTree1HasTree2(p1->right, p2->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 && pRoot2){
            if(isTree1HasTree2(pRoot1, pRoot2))
                return true;
            //左子树中搜索
            if(HasSubtree(pRoot1->left, pRoot2))
                return true;
            //右子树中搜索
            if(HasSubtree(pRoot1->right, pRoot2))
                return true;
            
        }
        return false;
    }
};
