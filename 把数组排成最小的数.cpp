class Solution {
public:
    static bool cmp(const int &a, const int& b){
        string sa = to_string(a), sb = to_string(b);
        if(sa+sb < sb+sa) 
            return true;
        return false;
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(auto i:numbers)
            res += to_string(i);
        return res;
    }
};
