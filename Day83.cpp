class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int temp = 0;
        for(int i=0;i<32;i++){
            if(left == right){
                break;
            }
            left = left >> 1;
            right = right >> 1;
            temp++;
        }
        while(temp--){
            left = left << 1;
        }
        return left;
    }
};