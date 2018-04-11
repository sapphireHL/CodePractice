class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(!numbers) return false;
        for(int i = 0; i < length; i++){
            int cur = numbers[i];
            if(cur != i){
                if(numbers[cur] == cur){
                    *duplication = cur;
                    return true;
                }
                while(numbers[cur] != cur)
                swap(numbers[cur], numbers[i]);
            }
        }
        return false;
    }
};
