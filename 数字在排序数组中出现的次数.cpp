class Solution {
public:
    int myLowerBound(vector<int> data, int start, int end, int k){
        while(start < end){
            int mid = start + (end - start) / 2;
            if(data[mid] >= k)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
    
    int myUpperBound(vector<int> data, int start, int end, int k){
        while(start < end){
            int mid = start + (end - start) / 2;
            if(data[mid] > k)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
    
    int GetNumberOfK(vector<int> data ,int k) {
        const int n = data.size();
        int first = myLowerBound(data, 0, n-1, k), last = myUpperBound(data, 0, n-1, k);
        if(last == n-1 && data[last] == k) last++;
        return last-first;
        //return upper_bound(data.begin(), data.end(), k)-lower_bound(data.begin(), data.end(), k);
    }
};
