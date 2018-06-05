class Solution {
public:
    bool check(char* str, char* pattern, int i, int j){
        if(str[i] == '\0'){
            if(pattern[j] == '\0') return true;
            if(pattern[j+1] == '*') return check(str, pattern, i, j+2);
            if(pattern[j] == '*') return check(str, pattern, i, j+1);
            else return false;//这里别忘了
        }
        if(pattern[j] == '\0') return false;
        if(pattern[j+1] == '*'){
            if(pattern[j] == '.' || str[i] == pattern[j])
                return check(str, pattern, i, j+2) || check(str, pattern, i+1, j+2) || check(str, pattern, i+1, j);
            else
                return check(str, pattern, i, j+2);
        }
        if(pattern[j] == '.' || str[i] == pattern[j]) return check(str, pattern, i+1, j+1);
        else return false;
    }
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern) return false;
        return check(str, pattern, 0, 0);
    }
};
