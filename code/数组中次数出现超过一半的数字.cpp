class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length == 0)
            return 0;
        if (length == 1)    //当长度为1的时候，下面的record仍然为0，所以需要单独提取出来
            return numbers[0];

        int times = 1;
        int record = 0;

        for (int i = 1; i < length; i++)
        {
            if (numbers[i] != numbers[i - 1])
            {
                if (times == 0)
                {
                    continue;
                }
                else
                    times--;
            }
            else
            {
                record = numbers[i];
                times++;
            }
        }

        return record;
    }
};
