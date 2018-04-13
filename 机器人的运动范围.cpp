class Solution {
public:
    typedef pair<int, int> node;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int getDigitSum(int x, int y){
        int res = 0;
        while(x){
            res += x%10;
            x /= 10;
        }
        while(y){
            res += y%10;
            y /= 10;
        }
        return res;
    }
    
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0) return 0;
        vector<vector<int>> visit(rows, vector<int>(cols));
        queue<node> q;
        q.push(node(0,0));
        int cnt = 0;
        while(!q.empty()){
            node cur = q.front();
            q.pop();
            visit[cur.first][cur.second] = 1;
            cnt++;
            for(int i=0; i<4; i++){
                node next(cur.first+dir[i][0], cur.second+dir[i][1]);
                if(next.first<0 || next.first>=rows || next.second <0 || next.second>=cols)
                    continue;
                if(visit[next.first][next.second] || getDigitSum(next.first, next.second) > threshold)
                    continue;
                q.push(next);
                visit[next.first][next.second] = 1;
            }
        }
        return cnt;
    }
};
