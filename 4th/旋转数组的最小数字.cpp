class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        const int n = rotateArray.size();
        if(n == 0) return 0;
        if(rotateArray[0] < rotateArray[n-1]) return rotateArray[0];
        int s = 0, e = n-1;
        int res = INT_MAX;
        while(s < e){
            if(e-s == 1){
                res = rotateArray[e];
                break;
            }
            int mid = s + (e-s)/2;
            if(rotateArray[s] == rotateArray[mid] && rotateArray[mid] == rotateArray[e]){
                for(int i=s; i<=e; ++i){
                    res = min(res, rotateArray[i]);
                }
                break;
            }
            //这两行判断没有等号会出错
            else if(rotateArray[mid] >= rotateArray[s]){
                s = mid;
            }
            else if(rotateArray[mid] <= rotateArray[e]){
                e = mid;
            }
        }
        return res;
    }
};
