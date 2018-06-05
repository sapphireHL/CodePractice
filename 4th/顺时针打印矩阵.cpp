class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int s = 0;
        const int n = matrix.size(), m = matrix[0].size();
        while(s*2 <  min(m, n)){
            //4 corners
            //s s, s m-1-s, n-1-s s, n-1-s m-1-s
            int deltai = n-1-s-s+1, deltaj = m-1-s-s+1;
            for(int i=s; i<=m-1-s; ++i)
                res.push_back(matrix[s][i]);
            
            if(deltai >  1){
                for(int i=s+1; i<=n-1-s; ++i)
                    res.push_back(matrix[i][m-1-s]);
            }
            
            if(deltai > 1 && deltaj > 1){
                for(int i=m-1-s-1; i>=s; --i)
                    res.push_back(matrix[n-1-s][i]);
            }
            
            if(deltai > 2 && deltaj > 1){
                for(int i=n-1-s-1; i>s; --i)
                    res.push_back(matrix[i][s]);
            }

            ++s;
        }
        return res;
    }
};
