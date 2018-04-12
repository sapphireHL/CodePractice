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
    int kth;
    bool find;
    TreeNode* res;
    void inorder(TreeNode* root){
        if(find) return;
        if(root){
            inorder(root->left);
            kth--;
            if(kth == 0){
                find = true;
                res =root;
            }
            inorder(root->right);
        }
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot) return nullptr;
        kth = k;
        find = false;
        res = nullptr;
        inorder(pRoot);
        return res;
    }

    
};
