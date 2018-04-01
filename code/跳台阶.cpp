class Solution {
public:
    int jumpFloor(int number) {
        int *jumpways = new int[number + 1];
        jumpways[0] = 0;

        if (number >= 1)
            jumpways[1] = 1;
        if (number >= 2)
            jumpways[2] = 2;

        for (int i = 3; i <= number; i++)
        {
            jumpways[i] = jumpways[i - 2] + jumpways[i - 1];
        }

        return jumpways[number];
    }
};
