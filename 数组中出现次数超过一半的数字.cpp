class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> mp;
        for(auto i:numbers){
            mp[i]++;
            if(mp[i] > (int)numbers.size()/2){
                return i;
            }
        }
        return 0;
    }
};
