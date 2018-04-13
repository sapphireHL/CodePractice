class Solution {
public:
    enum state{
        SIGN,
        PRENUM,
        SPOT,
        POSTNUM,
        E10,
        ESIGN,
        ENUM
    };
    
    bool isnumber(char* s){
        if(*s>='0' && *s<='9')
            return true;
        return false;
    }
    
    bool isNumeric(char* string)
    {
        if(!string) return false;
        state st, prest;
        if(*string == '+' || *string == '-') st = SIGN;
        else if(*string == '.') st = SPOT;
        else if(isnumber(string)) st = PRENUM;
        else return false;
        string++;
        while(*string != '\0'){
            switch (st){
                case SIGN:
                    if(isnumber(string)) st = PRENUM;
                    else if(*string == '.') st = SPOT;
                    else return false;
                    break;
                case PRENUM:
                    if(*string == '.') st = SPOT;
                    else if(*string == 'E' || *string == 'e') st = E10;
                    else if(!isnumber(string)) return false;
                    break;
                case SPOT:
                    if(isnumber(string)) st = POSTNUM;
                    else return false;
                    break;
                case POSTNUM:
                    if(*string == 'E' || *string == 'e') st = E10;
                    else if(!isnumber(string)) return false;
                    break;
                case E10:
                    if(isnumber(string)) st = ENUM;
                    else if(*string == '+' || *string == '-') st = ESIGN;
                    else return false;
                    break;
                case ESIGN:
                    if(isnumber(string)) st = ENUM;
                    else return false;
                    break;
                case ENUM:
                    if(!isnumber(string)) return false;
                    break;
            }
            ++string;
        }
        return st == PRENUM || st == POSTNUM || st == ENUM;
    }

};
