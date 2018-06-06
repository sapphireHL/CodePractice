class Solution {
public:
    int res;
    vector<vector<int>> visit;
    
    bool check(int i,int j, int the){
        int res = 0;
        while(i){
            res += i%10;
            i /= 10;
        }
        while(j){
            res += j%10;
            j /= 10;
        }
        return res <= the;
    }
    void dfs(int the, int rows, int cols, int i, int j){
        if(i<0 || i>=rows || j<0 || j>=cols) return;
        if(visit[i][j]) return;
        if(!check(i, j, the)) return;
        ++res;
        visit[i][j] = 1;
        dfs(the, rows, cols, i-1, j);
        dfs(the, rows, cols, i+1, j);
        dfs(the, rows, cols, i, j-1);
        dfs(the, rows, cols, i, j+1);
        //visit[i][j] = 0;//不用回溯！
    }
    int movingCount(int threshold, int rows, int cols)
    {
        res = 0;
        visit.resize(rows, vector<int>(cols));
        dfs(threshold, rows, cols, 0, 0);
        return res;
    }
};
