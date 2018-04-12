class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        const int n = str.size();
        int start = 0, end = n-1;
        //前后空格
        while(start < n && str[start] == ' ') start++;
        while(end >= 0 && str[end] == ' ') end--;
        //全是空格
        if(start == n) return 0;
        int sign = 1;
        if(str[start] == '+') start++;
        else if(str[start] == '-'){
            sign = -1;
            start++;
        }
        int num = 0;
        while(start <= end){
            if(str[start] >= '0' && str[start] <= '9'){
                num = num*10 + str[start]-'0';
            }
            else{
                return 0;
            }
            ++start;
        }
        return sign*num;
    }
};
