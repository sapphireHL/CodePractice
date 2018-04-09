class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int cnt = 0;
        unordered_map<int, int> times;
        for(int i:data){
            if(times.count(i)) times[i] = 0;
            else times[i] = 1;
        }
        for(auto i:times){
            if(i.second != 0){
                if(cnt++ == 0){
                    *num1 = i.first;
                }
                else {
                    *num2 = i.first;
                    return;
                }
            }
        }
    }
};
