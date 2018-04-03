class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int numloc = 0;
        int call_m = 0;
        int lastnum = n;
        bool *visited = new bool[n];

        for (int i = 0; i < n; i++)
            visited[i] = false;

        while (lastnum > 1) {
            if (visited[numloc] == false)
            {
                call_m++;
                if (call_m == m)
                {
                    call_m = 0;
                    visited[numloc] = true;
                    lastnum--;
                }
            }
            numloc = (numloc + 1) % n;
        }

        for (int i = 0; i < n; i++)
            if (visited[i] == false)
                return i;
        return -1;
    }
};

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 1 || m <= 0)
            return -1;
        int lastnum = 0;

        for (int i = 2; i <= n; i++)
            lastnum = (lastnum + m) % i;
        return lastnum;
    }
};
