/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(const vector<int>& pre, int prestart, const vector<int>& vin, int instart, int inend){
        if(instart > inend) return nullptr;
        if(instart == inend) return new TreeNode(vin[instart]);
        TreeNode* root = new TreeNode(pre[prestart]);
        for(int i = instart; i <= inend; i++){
            if(vin[i] == pre[prestart]){
                root->left = construct(pre, prestart+1, vin, instart, i-1);
                root->right = construct(pre, prestart+i-instart+1, vin, i+1, inend);
            }
        }
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return construct(pre, 0, vin, 0, vin.size()-1);
    }
};
