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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            queue<TreeNode*> q;
            if(!pRoot) 
                return res;
            q.push(pRoot);
            while(!q.empty()){
                int len = q.size();
                vector<int> line;
                for(int i = 0; i < len; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    line.push_back(cur->val);
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                }
                res.push_back(line);
            }
            return res;
        }
    
};
