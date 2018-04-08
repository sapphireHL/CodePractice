class Solution {
public:
    bool isPostOrder(vector<int>& seq, int start, int end){
        if(start >= end) return true;
        //最后一个是根节点
        int root = seq[end];
        //找到第一个比根节点大的，左边是左子树，右边是右子树
        int mid = start;
        while(mid < end && seq[mid] < root) ++mid;
        //检查后面是不是都比根节点大
        for(int i=mid; i<end; i++){
            if(seq[i] < root)
                return false;
        }
        //递归左右
        return isPostOrder(seq, start, mid-1) && isPostOrder(seq, mid, end-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        const int n = sequence.size();
        if(n == 0) return false;
        return isPostOrder(sequence, 0, n-1);
    }
};
