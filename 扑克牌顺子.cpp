class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 5) return false;
        sort(numbers.begin(), numbers.end());
        int i = 0, zeros = 0;
        while(i < numbers.size() && numbers[i] == 0) ++i;
        zeros = i;//有多少个0
        while(++i < numbers.size()){
            if(numbers[i] == numbers[i-1]) return false;//如果相等无论如何都无法顺子
            if(numbers[i] - numbers[i-1] == 1) continue;
            else if(numbers[i] - numbers[i-1] > 1){
                if(numbers[i] - numbers[i-1] - 1 > zeros)
                    return false;
                zeros -= numbers[i] - numbers[i-1] - 1;
            }
        }
        return true;
    }
};
