class sum{
public:
    static int value;
    static int total;
    sum(){
        ++value;
        total += value;
    }
    static void reset(){
        value = 0;
        total = 0;
    }
};
int sum::value = 0;
int sum::total = 0;
    
class Solution {
public:
    int Sum_Solution(int n) {
        sum::reset();
        vector<sum> a(n);
        return sum::total;
    }
};
