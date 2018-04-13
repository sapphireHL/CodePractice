class Solution {
public:
    void Insert(int num)
    {
        data.insert(num);
    }

    double GetMedian()
    { 
        int step = data.size() / 2;
        auto it = data.begin();
        while(step--) ++it;
        if(data.size() % 2 == 1){
            return *it;
        }
        else{
            double second = *it;
            --it;
            double first = *it;
            return (first+second)/2;
        }
    }
private:
    multiset<int> data;
};
