class Solution {
public:
    double myPower(double base, int exp){
        if(exp == 0) return 1;
        if(exp == 1) return base;
        if(exp % 2 == 0){
            double tmp = myPower(base, exp / 2);
            return tmp*tmp;
        }
        else{
            double tmp = myPower(base, (exp - 1) / 2);
            return base*tmp*tmp;
        }
    }
    double Power(double base, int exponent) {
        if(base == 0)
            return 0;
        if(exponent < 0)
            return myPower(1.0 / base, -exponent);
        return myPower(base, exponent);
    }
};
