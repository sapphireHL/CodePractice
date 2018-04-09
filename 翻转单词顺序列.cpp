class Solution {
public:
    void reverse(string& s, int l, int r){
        for(int i=l; i<(l+r+1)/2; i++){
            swap(s[i], s[r-i+l]);
        }
    }
    string ReverseSentence(string str) {
        //去除前后空格
        reverse(str, 0, str.size()-1);
        int pre = 0;
        for(int i = 0; i < str.size(); i++){
            if(i == str.size()-1)
                reverse(str, pre, i);
            if(str[i] == ' '){
                reverse(str, pre, i-1);
                pre = i+1;
            }
        }
        return str;
    }
};
