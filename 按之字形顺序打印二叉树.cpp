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
        if(!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        int step = 0;
        while(!q.empty()){
            int len = q.size();
            vector<int> tmp;
            for(int i = 0; i < len; i++){
                auto cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(step%2 == 1){
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);
            ++step;
        }
        return res;
    }
    
};
