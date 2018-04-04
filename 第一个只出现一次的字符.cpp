class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> mp;
        for(int i = 0; i < str.size(); i++){
            if(mp.count(str[i]))
                mp[str[i]] = -1;
            else
                mp[str[i]] = i;
        }
        int min_index = INT_MAX;
        for(auto i:mp){
            if(i.second == -1)continue;
            min_index = min(min_index, i.second);
        }
        return min_index == INT_MAX? -1 : min_index;
    }
};
