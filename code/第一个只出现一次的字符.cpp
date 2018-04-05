class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int recordnum[129];

        int length = str.size();

        memset(recordnum, 0, sizeof(recordnum));

        for (int i = 0; i < length; i++)
        {
            recordnum[str[i]]++;
        }

        for (int i = 0; i < length; i++)
        {
            if (recordnum[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
