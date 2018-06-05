class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int res = INT_MIN, localmax = 0;
        for(int i:array){
            localmax += i;
            
            //下面两行顺序不能反，如果全负数会出错
            res = max(res, localmax);
            if(localmax < 0) localmax = 0;
        }
        return res;
    }
};
