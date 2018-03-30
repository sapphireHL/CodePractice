class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int num = n;
         int cnt = 0;
         while(num != 0){
             if(num % 2 == 1)
                 cnt++;
             num /= 2;
         }
         return cnt;
     }
};
