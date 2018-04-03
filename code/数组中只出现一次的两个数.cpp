class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int length = data.size();
        *num1 = 0;
        *num2 = 0;
        if (length == 0)
            return ;

        int num = 0;
        for (int i = 0 ; i < length; i++)
            num = data[i] ^ num;
        int loc = GetFirstBit1(num);
        if (loc == 0)
            return ;

        for (int i = 0; i < length; i++)
        {
            if ((data[i] >> loc) & 0x1)
                *num1 = *num1 ^ data[i];
            else
                *num2 = *num2 ^ data[i];
        }
        return;

    }
    int GetFirstBit1(int num)
    {
        int loc = 0;
        while (num != 0 && loc < 8 * sizeof(int)) {
            if (num & 0x1)
                break;
            num = num >> 1; //注意这里需要改变num的值。
            loc++;
        }
        return loc;
    }
};
