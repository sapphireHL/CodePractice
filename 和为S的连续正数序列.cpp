class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum < 3) return res;
        int first = 1, last = sqrt(2*sum);
        int total = (first+last)*(last-first+1)/2;
        while(first < last){
            if(total > sum){
                total -= first;
                ++first;
            }
            else if(total < sum){
                ++last;
                total += last;
            }
            else{
                vector<int> tmp;
                for(int i=first; i<=last; i++){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                total -= first;
                ++first;
            }
        }
        return res;
    }
};
