class Solution {
public:
    vector<string> allstr;
    int curloc = 0;
    vector<string> Permutation(string str) {
        int length = str.size();

        if (length == 0)
            return allstr;

        if (curloc == length - 1)
        {
            allstr.push_back(str);
            return allstr;
        }
        for (int i = curloc; i < length; i++)
        {
            if (i != curloc && str[i] == str[curloc])   //当后面的字母相同时没有必要继续，但是第一个字母需要
                continue;
            swap(str[i], str[curloc]);
            curloc++;   //注意这个的位置
            Permutation(str);
            curloc--;
            swap(str[i], str[curloc]);

        }
        sort(allstr.begin(), allstr.end());
        return allstr;
    }
};
