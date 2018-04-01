class Solution {
public:
    int  NumberOf1(int n) {
        int count1number = 0;

        while (n != 0)
        {
            count1number++;
            n = n & (n - 1);
        }

        return count1number;
    }
};
