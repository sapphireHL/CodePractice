class Solution {
public:
    int jumpFloorII(int number) {
        return 1<<(number-1);
    }
};
//f(n)=f(n-1)+f(n-2)+...+f(1)+f(0)
//    =2f(n-2)+...+2f(1)+2f(0)
//    =2^n-1 f(0)
