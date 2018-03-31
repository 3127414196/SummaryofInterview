class Solution {
public:
    int jumpFloorII(int number) {
        int jumpways = 1;

        jumpways = jumpways << (number - 1);

        return (number == 0) ? 0 : jumpways;
    }
};
