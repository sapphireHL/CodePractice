class Solution {
public:
    void partition(vector<int>& data, int left, int right, int k){
        if(left >= right) return;
        int pivot = data[left];
        int i = left, j = right;
        while(i < j){
            while(i < j && data[j] >= pivot) --j;
            while(i < j && data[i] <= pivot) ++i;
            if(i < j)
                swap(data[i], data[j]);
        }
        swap(data[j], data[left]);
        partition(data, left, j-1, k);
        partition(data, j+1, right, k);
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k > input.size())
            return res;
        partition(input, 0, input.size()-1, k);
        for(int i=0; i<k; ++i){
            res.push_back(input[i]);
        }
        return res;
    }
};
