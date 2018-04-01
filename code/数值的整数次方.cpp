class Solution {
public:
    double Power(double base, int exponent) {
        int unsignedexponent = abs(exponent);
        double result = 1;

        if (base == 0)
            return 0;

        while (unsignedexponent > 0)
        {
            result = result * base;
            unsignedexponent--;
        }

        if (exponent < 0)
            return 1.0 / result;
        else
            return result;
    }
};
