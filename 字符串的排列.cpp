class Solution {
public:
    void dfs(string& str, int start){
        if(start == str.size()){
            res.push_back(str);
            return;
        }
        for(int i=start; i<str.size(); i++){
            if(i == start || str[i] != str[start]){
                swap(str[start], str[i]);
                dfs(str, start+1);
                swap(str[start], str[i]);
            }
            
        }
        
    }
    vector<string> Permutation(string str) {
        if(str.empty()) return res;
        dfs(str, 0);
        sort(res.begin(), res.end());
        return res;
    }
private:
    vector<string> res;
};
