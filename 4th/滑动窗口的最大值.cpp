class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(size == 0 || size > num.size()) return res;//size=0判断不可少！
        deque<int> q;
        for(int i=0; i<size; ++i){
            while(q.size() && num[i] > num[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(num[q.front()]);//注意这里和13行
        for(int i=size; i<num.size(); ++i){
            while(q.size() && num[i] > num[q.back()])
                q.pop_back();
            q.push_back(i);
            if(i-q.front() >= size) q.pop_front();
            res.push_back(num[q.front()]);//循环最后才加入最大值
        }
        return res;
    }
};
