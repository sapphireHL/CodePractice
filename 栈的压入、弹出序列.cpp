class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        int cnt = 0;
        for(int i = 0; i < pushV.size(); i++){
            while(!stk.empty() && stk.top() == popV[cnt]){
                stk.pop();
                cnt++;
            }
            stk.push(pushV[i]);
        }
        while(cnt < popV.size()){
            if(stk.top() != popV[cnt])
                return false;
            stk.pop();
            cnt++;
        }
        return true;
    }
};
