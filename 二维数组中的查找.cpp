class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int i = 0, j = array[0].size() - 1;
        while(i < array.size() && j >= 0){
            if(array[i][j] > target){
                j--;
            }
            else if(array[i][j] < target){
                i++;
            }
            else
                return true;
        }
        return false;
    }
};
