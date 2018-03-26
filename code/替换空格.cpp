class Solution {
public:
	void replaceSpace(char *str,int length) {
	    int block = 0;
	    int strlength = 0;

        if(str == NULL || length <= 0)
            return;

	    for (int i = 0; str[i] != '\0'; i++)
        {
            strlength ++;
            if (str[i] == ' ')
                block++;
        }

        int endlength = block * 2 + strlength;
        int nowend = strlength;

        if(endlength >= length)
            return;

        while(nowend < endlength  && nowend >= 0)
        {
            if (str[nowend] == ' ') //注意需要考虑多个空格一起的问题
            {
                str[endlength--] = '0';
                str[endlength--] = '2';
                str[endlength--] = '%';
            }
            else
                str[endlength--] = str[nowend];
            nowend--;
        }
	}
};
