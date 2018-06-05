class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        for(int i=1; i<=n; i*=10){
            int a = n/i, b = n%i;
            res += a/10*i;
            if(a%10 > 1) res += i;
            if(a%10 == 1) res += b+1;
        }
        return res;
    }
};
