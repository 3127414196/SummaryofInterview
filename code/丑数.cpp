class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;

        int *uglynum = new int[index + 1];
        uglynum[0] = 1;
        int puglyum = 1;
        int needmult2 = 0;
        int needmult3 = 0;
        int needmult5 = 0;

        for ( ; puglyum < index; puglyum++)
        {
            uglynum[puglyum] = min(uglynum[needmult2] * 2, min(uglynum[needmult3] * 3, uglynum[needmult5] * 5));

            if (uglynum[puglyum] == uglynum[needmult2] * 2)
                needmult2++;
            if (uglynum[puglyum] == uglynum[needmult3] * 3)
                needmult3++;
            if (uglynum[puglyum] == uglynum[needmult5] * 5)
                needmult5++;
        }

        return uglynum[index - 1];
    }
};
