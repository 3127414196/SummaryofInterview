class Solution {
public:
    typedef int (*fun) (int n);

    static int Sum_Solution_Teminator(int n) {
        return 0;
    }
    static int Sum_Solution(int n) {
        static fun f[2] = {Sum_Solution_Teminator, Sum_Solution};
        return n + f[!!n](n - 1);
    }
};
