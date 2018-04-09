class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int left = 0, right = array.size()-1;
        while(left < right){
            if(array[left] + array[right] < sum)
                left++;
            else if(array[left] + array[right] > sum)
                right--;
            else{
                res.push_back(array[left]);
                res.push_back(array[right]);
                return res;
            }
        }
        return res;
    }
};
