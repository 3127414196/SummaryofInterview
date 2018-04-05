class Solution {
public:
    string LeftRotateString(string str, int n) {
        int length = str.length();
        if (length == 0 || n > length || n < 0)
            return str;
        string temp = str;
        int i = 0;
        int ptemp = 0;
        for (i = 0; i < length - n; i++)
            str[i] = str[i + n];

        for (; i < length; i++)
        {
            str[i] = temp[ptemp];
            ptemp++;
        }
        return str;
    }
};
