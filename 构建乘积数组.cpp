class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        const int n = A.size();
        vector<int> prefix(n, 1), postfix(n, 1);
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * A[i-1];
        }
        for(int i=n-2; i>=0; i--){
            postfix[i] = postfix[i+1] * A[i+1];
        }
        vector<int> res(n);
        for(int i=0; i<n; i++)
            res[i] = prefix[i] * postfix[i];
        return res;
    }
};
