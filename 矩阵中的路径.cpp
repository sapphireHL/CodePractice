class Solution {
public:
    vector<vector<int>> visit;
    bool find;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool check(int rows, int cols, int i, int j){
        if(i<0 || i>=rows || j<0 || j>=cols) return false;
        return true;
    }
    
    void dfs(char* matrix, int rows, int cols, char* str, int i, int j, int len, int cur){
        if(matrix[i*cols+j] != str[cur]) return;
        if(cur == len-1){
            find = true;
            return;
        }
        for(int k=0; k<4; k++){
            int nexti = i+dir[k][0], nextj = j+dir[k][1];
            if(check(rows, cols, nexti, nextj) && !visit[nexti][nextj]){
                visit[nexti][nextj] = 1;
                dfs(matrix, rows, cols, str, nexti, nextj, len, cur+1);
                visit[nexti][nextj] = 0;
            }
        }
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(!matrix) return false;
        if(!str) return true;
        int len = strlen(str);
        find = false;
        visit.resize(rows, vector<int>(cols));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[cols*i+j] == str[0]){
                    visit[i][j] = 1;
                    dfs(matrix, rows, cols, str, i, j, len, 0);
                    visit[i][j] = 0;
                    if(find){
                        return true;
                    }
                }
            }
        }
        
        return find;
    }


};
