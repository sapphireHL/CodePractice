class Solution {
public:
    long long merge(vector<int>&data, int s, int m, int e){
        vector<int> tmp(e-s+1);
        int i=s, j=m+1, cnt = 0;
        long long res = 0;
        while(i<=m && j<=e){
            if(data[j] < data[i]){
                res +=  m-i+1;
                res %= 1000000007;
                tmp[cnt++] = data[j++];
            }
            else{
                tmp[cnt++] = data[i++];
            }
        }
        while(i<=m) tmp[cnt++] = data[i++];
        while(j<=e) tmp[cnt++] = data[j++];
        for(int i=s; i<=e; ++i){
            data[i] = tmp[i-s];
        }
        return res;
    }
    int mergesort(vector<int>& data, int s, int e){
    //注意这里退出条件，大于等于！！！
        if(s >= e) return 0;
        int mid = s+(e-s)/2;
        long long l = mergesort(data, s, mid);
        long long r = mergesort(data, mid+1, e);
        long long rest = merge(data, s, mid, e);
        return (l+r+rest)%1000000007;
    }
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        return mergesort(data, 0, data.size()-1);
    }
};
