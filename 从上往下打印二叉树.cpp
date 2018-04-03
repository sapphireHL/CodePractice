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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(!root) 
            return res;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> line;
            for(int i = 0; i < len; i++){
                TreeNode* cur = q.front();
                q.pop();
                res.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return res;
    }
};
