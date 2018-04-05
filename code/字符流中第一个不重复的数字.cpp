class Solution
{
public:
  //Insert one char from stringstream
    int hashtable[129];
    vector<char> onech;

    void Insert(char ch)
    {
        if (hashtable[ch] == 0)
            onech.push_back(ch);
        hashtable[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char record = '#';
        int i = 0;
        int length = onech.size();
        while (i < length) {
            if (hashtable[onech[i]] == 1)
            {
                record = onech[i];
                break;
            }
            i++;
        }
        return record;
    }
};
