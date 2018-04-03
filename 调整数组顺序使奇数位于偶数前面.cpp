class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> evens;
        int cnt = 0;
        for(int i=0; i<array.size(); i++){
            if(array[i]%2 == 0)
                evens.push_back(array[i]);
            else
                array[cnt++] = array[i];
        }
        for(auto i:evens){
            array[cnt++] = i;
        }
    }
};
