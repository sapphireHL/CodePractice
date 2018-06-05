class Solution {
public:
    int lower(const vector<int>& data ,int k){
        int l = 0, h = data.size()-1;
        while(l < h){
            int mid = l+(h-l)/2;
            if(data[mid] >= k) h = mid;
            else l = mid + 1;
        }
        if(data[l] != k) return -1;
        return l;
    }
    int upper(const vector<int>& data ,int k){
        int l = 0, h = data.size()-1;
        while(l < h){
            int mid = l+(h-l+1)/2;//这里不加1会无限循环！因为l=mid，永远是停在前一个
            if(data[mid] > k) h = mid-1;
            else l = mid;
        }
        if(data[l] != k) return -1;
        return l;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int l = lower(data, k), h = upper(data ,k);
        if(l == -1) return 0;
        return h-l+1;
    }
};
