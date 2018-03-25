<!-- GFM-TOC -->
* [面试需要的基本知识](#面试需要的基本知识)
<!-- GFM-TOC -->

# 面试需要的基本知识
## 空类型
```c++
#include <iostream>

using namespace std;

class studentA
{
public:
    studentA()
    {
        cout << "I'm student" << endl;
    }
};
class studentB
{
public:
    studentB()
    {
        cout << "I'm student" << endl;
    }
    virtual ~studentB()
    {
        cout << "~studentB" << endl;
    }
};
int main()
{
    studentA a;
    cout << sizeof(void) << endl;
    cout << sizeof(studentA) << endl;
    cout << sizeof(studentB) << endl;
    return 0;
}
```
> 输出为
```
I'm student
1
1
4
```
## 数组
> `sizeof`算数组大小的时候不算`'\0'`
``` c++
char data[] = {1, 2, 3, 4, 5};
cout << sizeof(data) << endl;
```
> 输出为
```
20
```
