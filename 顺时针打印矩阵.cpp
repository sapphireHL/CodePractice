class Solution {
public:
    
	int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
	int direction = 0;

	bool check(vector<vector<int> >& matrix, int i, int j) {
		if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == INT_MIN)
			return false;
        return true;
	}
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.empty())
			return vector<int>();
        vector<int> res;
        int i = 0, j = 0;
        while(res.size() < matrix.size()*matrix[0].size()){
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            if (!check(matrix, i + dir[direction][0], j + dir[direction][1]))
			        direction = ++direction % 4;
            i += dir[direction][0];
            j += dir[direction][1];
        }
		return res;
	}
};
