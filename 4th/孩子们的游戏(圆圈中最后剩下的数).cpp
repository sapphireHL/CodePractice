//迭代方法
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0 || m == 0) return -1;
        vector<int> childs(n);
        for(int i=0; i<n; ++i) childs[i] = i;
        int cur = 0;
        while(childs.size()>1){
            cur += m-1;
            cur %= childs.size();
            auto it = childs.begin();
            it += cur;
            childs.erase(it);   
        }
        return childs[0];
    }
};
