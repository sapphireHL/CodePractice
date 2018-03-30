class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        mp[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto ch : s){
            if(mp[ch] == 1)
                return ch;
        }
        return '#';
    }
    string s;
    unordered_map<char, int> mp;
};
