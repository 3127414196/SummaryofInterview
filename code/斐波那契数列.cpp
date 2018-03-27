class Solution {
public:
    int Fibonacci(int n) {
        int fn[40];

        fn[0] = 0;
        fn[1] = 1;
        fn[2] = 1;

        if (n <= 2)
            return fn[n];

        for (int i = 3; i < n; i++)
        {
             fn[i] = fn[i - 1] + fn[i - 2];
        }

        return fn[n];
    }
};
