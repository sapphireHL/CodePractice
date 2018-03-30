//双栈，时间O(1),空间O（n）
class Solution {
public:
    void push(int value) {
        data.push(value);
        //若栈空或者value小于等于栈顶元素就push，这样minstack栈顶就是保存的最小元素，这里必须是小于等于
        if(minStack.empty() || value <= minStack.top())
            minStack.push(value);
    }
    void pop() {
        //如果当前data栈顶元素等于最小值，minstack也pop
        if(data.top() == minStack.top())
            minStack.pop();
        data.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> data, minStack;
};


//每次push的是value和当前最小值的差
//时间O（1），空间O（1）
class Solution {
public:
    void push(int value) {
        //若栈空，将value入栈，minv=value
        if(data.empty()){
            minv = value;
            data.push(value);
        }
        //每次先push的是value-minv,若value更小，则更新minv
        else{
            data.push(value-minv);
            minv = value < minv? value : minv;
        }
    }
    void pop() {
        //栈顶大于等于0，说明最后一个元素大于minv，直接出栈
        if(data.top() >= 0){
            data.pop();
        }
        //栈顶小于0，说明最后一个元素小于minv，更新minv
        else{
            minv = minv - data.top();
            data.pop();
        }
    }
    int top() {
        return data.top();
    }
    int min() {
        return minv;
    }
private:
    stack<int> data;
    int minv;
};
