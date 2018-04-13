class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0 || m == 0) return -1;
        vector<int> childs;
        for(int i=0; i<n; i++)
            childs.push_back(i);
        
        int cur = 0;
        while(childs.size() > 1){
            int gap = m % childs.size();
            cur += gap-1;
            if(cur < 0) cur += childs.size();
            if(cur >= childs.size()) cur -= childs.size();
            auto it = childs.begin();
            it += cur;
            childs.erase(it);
            if(cur >= childs.size()) cur -= childs.size();
        }
        return childs.back();
    }
};
