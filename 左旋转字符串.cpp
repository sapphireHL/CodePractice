class Solution {
public:
    string LeftRotateString(string str, int n) {
        deque<char> s(str.begin(), str.end());
        for(int i=0; i<n; i++){
            s.push_back(s.front());
            s.pop_front();
        }
        string res(s.begin(), s.end());
        return res;
    }
};
