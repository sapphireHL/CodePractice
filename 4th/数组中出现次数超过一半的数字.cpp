class Solution {
public:
    int partition(vector<int>& numbers, int s, int e){
        int &pivot = numbers[s];
        while(s < e){
            while(s < e && numbers[e] >= pivot) --e;
            while(s < e && numbers[s] <= pivot) ++s;
            if(s<e) swap(numbers[s], numbers[e]);
        }
        swap(pivot, numbers[s]);
        return s;
    }
    
    bool check(const vector<int>& numbers, int mid){
        int cnt = 0;
        for(int i:numbers){
            if(i == numbers[mid])++cnt;
        }
        return cnt>numbers.size()/2;
    }
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        const int n = numbers.size();
        int s = 0, e = n-1;
        while(s < e){
            int mid = partition(numbers, s, e);
            if(mid == n/2){
                if(check(numbers, mid))
                    return numbers[mid];
            }
            if(mid < n/2)
                s = mid+1;
            else
                e = mid-1;
        }
        //退出循环后判断一下
        if(check(numbers, s))
                return numbers[s];
        return 0;
    }
};
