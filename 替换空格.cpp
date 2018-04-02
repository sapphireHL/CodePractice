class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s;
        for(int i = 0; i < length; i++){
            if(str[i] == ' '){
                s += "%20";
            }
            else
                s += str[i];
        }
        strcpy(str, s.c_str());
	}
};
