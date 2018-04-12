class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int howmuch = n, res = 0, base = 1;
        while(howmuch){
            int curnumber = howmuch % 10;
            howmuch /= 10;
            res += base*howmuch;
            if(curnumber == 1){
                res += n % base + 1;
            }
            else if(curnumber > 1)
                res += base;
            base *= 10;
        }
        return res;
    }
};
