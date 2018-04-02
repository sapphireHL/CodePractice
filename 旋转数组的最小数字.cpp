class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size()-1;
        //未旋转，第一个最小
        if(rotateArray[left] < rotateArray[right])
            return rotateArray[left];
        while(right - left > 1){
            int mid = left + (right - left + 1) / 2;
            //左右两端相等，顺序查找
            if(rotateArray[left] == rotateArray[right]){
                while(++left <= right){
                    if(rotateArray[left] < rotateArray[left-1])
                        return rotateArray[left];
                }
            }
            //mid在前半段，注意是大于等于
            else if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }
            //mid在后半段，注意是小于等于
            else if(rotateArray[mid] <= rotateArray[right]){
                right = mid;
            }
        }
        return rotateArray[right];
    }
};
