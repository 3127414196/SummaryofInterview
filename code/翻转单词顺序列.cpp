class Solution {
public:
    string ReverseSentence(string str) {
        int length = str.length();

        if (length == 0 || str.find(' ') == std::string::npos)  //当没有空格时不需要翻转
            return str;
        str = ReverseSentence(str, 0, length - 1);

        int begin = 0;
        int end = 0;
        for (; end < length; end++)
        {
            if (str[end] == ' ')
            {
                str = ReverseSentence(str, begin, end - 1);
                begin = end + 1;
            }
        }
        if (begin < end)    //翻转最后一个单词
            str = ReverseSentence(str, begin, end - 1);

        return str;
    }
    string ReverseSentence(string str, int begin, int end) {
        while (begin < end) {
            swap(str[begin], str[end]);
            begin++;
            end--;
        }
        return str;
    }
};
