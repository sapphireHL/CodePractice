class Solution {
public:
    int depth(TreeNode* root){
        if(root){
            int left = depth(root->left);
            int right = depth(root->right);
            return max(left, right)+1;
        }
        else
            return 0;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)
            return true;
        int left = depth(pRoot->left), right = depth(pRoot->right);
        return abs(left-right) <= 1;
    }
};
