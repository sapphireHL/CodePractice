class Solution {
public:
    int Add(int num1, int num2)
    {
        int sumNoCarry = 0;//不包含进位的和，异或得到
        int carry = 0;//进位，相与得到
        do{
            sumNoCarry = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sumNoCarry;
            num2 = carry;
        }while(carry != 0);
        
        return sumNoCarry;
    }
};
