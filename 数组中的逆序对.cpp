class Solution {
public:
    long long merge(vector<int>& data, int start, int mid, int end){
        vector<int> tmp(end-start+1);
        int i = start, j = mid + 1, cnt = 0;
        long long res = 0;
        while(i <= mid && j <= end){
            if(data[i] <= data[j])
                tmp[cnt++] = data[i++];
            else{
                //有mid-i+1个逆序对
                res += (mid-i+1);
                res %= 1000000007;
                tmp[cnt++] = data[j++];
            }
        }
        while(i <= mid) tmp[cnt++] = data[i++];
        while(j <= end) tmp[cnt++] = data[j++];
        for(int i = start; i <= end; i++)
            data[i] = tmp[i-start];
        return res;
    }
    
    int mergeSort(vector<int>& data, int start, int end){
        if(start >= end) return 0;
        int mid = start + (end - start) / 2;
        int left = mergeSort(data, start, mid);
        int right = mergeSort(data, mid+1, end);
        int all = merge(data, start, mid, end);
        return (left + right + all) % 1000000007;
    }
    
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        return mergeSort(data, 0, data.size()-1);
    }
};
