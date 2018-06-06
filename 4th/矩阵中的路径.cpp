class Solution {
public:
    vector<vector<int>> visit;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool check(char* matrix, int rows, int cols, char* str, int i, int j, int cur){
        if(str[cur] == '\0') return true;//这个条件放第一个
        if(i<0 || i>=rows || j<0 || j>=cols) return false;
        if(visit[i][j] == 1) return false;
        if(matrix[i*cols+j] != str[cur]) return false;
        visit[i][j] = 1;
        bool res = check(matrix, rows, cols, str,i-1, j, cur+1)
            || check(matrix, rows, cols, str, i+1, j, cur+1)
            || check(matrix, rows, cols, str, i, j-1, cur+1)
            || check(matrix, rows, cols, str, i, j+1, cur+1);
        visit[i][j] = 0;
        return res;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(!str) return false;
        if(rows*cols < strlen(str)) return false;
        visit.resize(rows, vector<int>(cols));
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(matrix[i*cols+j] == str[0]){
                    if(check(matrix, rows, cols, str, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }


};
