class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int length = numbers.size();
        if (length == 0)
            return false;
        sort(numbers.begin(), numbers.end());

        int count0 = 0;
        int gap = 0;
        for(int i = 0; i < length; i++)
        {
            if (numbers[i] == 0)
                count0++;
        }
        for(int i = count0 + 1; i < length; i++)
        {
            if (numbers[i] == numbers[i - 1])
                return false;
            gap = gap + numbers[i] - numbers[i - 1] - 1;
        }
        return (gap > count0) ? false : true;
    }
};
