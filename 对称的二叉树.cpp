/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* p1, TreeNode* p2)
    {
        if(!p1 && !p2) return true;
        if((p1 && !p2) ||(!p1 && p2)) return false;
        if(p1->val != p2->val) return false;
        return isSymmetrical(p1->left, p2->right) && isSymmetrical(p1->right, p2->left);
    }
    
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }

};
