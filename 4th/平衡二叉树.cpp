class Solution {
public:
    bool check(TreeNode* root, int& len){
        if(!root){
            len = 0;
            return true;
        }
        int l, r;
        //注意这里的判断
        if(check(root->left, l) && check(root->right, r)){
            len = max(l, r)+1;
            if(abs(l-r) <= 1) return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int len;
        return check(pRoot, len);
    }
};
