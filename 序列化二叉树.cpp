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
    void Serialize(TreeNode* root, string &s){
        if(root){
            s += to_string(root->val);
            s += ' ';
            Serialize(root->left, s);
            Serialize(root->right, s);
        }
        else{
            s += "# ";
        }
    }
    
    TreeNode* Deserialize(istringstream & in){
        string cur;
        if(in >> cur){
            if(cur == "#"){
                return nullptr;
            }
            TreeNode* root = new TreeNode(stoi(cur));
            root->left = Deserialize(in);
            root->right = Deserialize(in);
            return root;
        }
        return nullptr;
    }
    
    char* Serialize(TreeNode *root) {    
        string s;
		Serialize(root, s);
		char* res = new char[s.size() + 1];
		strcpy(res, s.c_str());
		return res;
    }
    
    TreeNode* Deserialize(char *str) {
        string s(str);
        istringstream in(s);
        return Deserialize(in);
    }
};
