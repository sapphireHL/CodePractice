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
	vector<vector<int> > res;
	vector<int> path;

	void dfs(TreeNode* root, int target) {
		if (root) {
			path.push_back(root->val);
			target -= root->val;
			if (!root->left && !root->right) {
				if (target == 0)
					res.push_back(path);
				path.pop_back();
				return;
			}
			dfs(root->left, target);
			dfs(root->right, target);
			target += root->val;
			path.pop_back();
		}
	}

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		dfs(root, expectNumber);
		return res;
	}
};
