<!-- GFM-TOC -->
* [内存分配方式](#内存分配方式)  
* [堆和栈的区别](#堆和栈的区别)  
* [有了malloc/free为什么还要new/delete](#有了malloc/free为什么还要new/delete？)  
* [指针与引用的区别](#指针与引用的区别)  
* [指针与数组的对比](#指针与数组的对比)  
* [类的大小的计算](#类的大小的计算)  
* [多态](#多态)
* [单继承多继承](#单继承多继承)  
* [虚函数](#虚函数)
* [虚析构函数](#虚析构函数)
* [父类指针指向子类指针时调用哪个函数](#父类指针指向子类指针时调用哪个函数)
<!-- GFM-TOC -->

# 内存分配方式
1. 栈 : 函数内局部变量(注意不要返回栈内存的指针或引用，因为return会自动销毁栈)
2. 堆 : new 分配内存块(程序结束后会自动回收，但是在运行过程中不会被释放，可能会由于一直调用分配导致内存泄漏)
3. 自由存储区 : malloc(程序结束后会自动回收，同上，free后需要将指针赋值为NULL)
4. 全局/静态存储区 : 全局变量和静态变量
5. 常量存储区 : 存放常量("hello"),程序结束后由系统释放，注意当指针指向`char* p = "hello"; p[0] = 'X'`运行时错误

# 堆和栈的区别
1. 管理方式不同
> 对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。

2. 空间大小不同
> 一般来讲在32位系统下，堆内存可以达到4G的空间，从这个角度来看堆内存几乎是没有什么限制的。但是对于栈来讲，一般都是有一定的空间大小的，例如，在VC6下面，默认的栈空间大小是1M

3. 能否产生碎片不同
> 对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出，在他弹出之前，在他上面的后进的栈内容已经被弹出.

4. 生长方向不同；
> 对于堆来讲，生长方向是向上的，也就是向着内存地址增加的方向；对于栈来讲，它的生长方向是向下的，是向着内存地址减小的方向增长。

5. 分配方式不同；
> 堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。

6. 分配效率不同；
> 栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的，例如为了分配一块内存，库函数会按照一定的算法（具体的算法可以参考数据结构/操作系统）在堆内存中搜索可用的足够大小的空间，如果没有足够大小的空间（可能是由于内存碎片太多），就有可能调用系统功能去增加程序数据段的内存空间，这样就有机会分到足够大小的内存，然后进行返回。显然，堆的效率比栈要低得多。

# 有了malloc/free为什么还要new/delete？
1. malloc与free是C++/C语言的标准库函数，new/delete是C++的运算符。它们都可用于申请动态内存和释放内存。
2. 对于非内部数据类型的对象而言，光用maloc/free无法满足动态对象的要求。对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由于malloc/free是库函数而不是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加于malloc/free。因此C++语言需要一个能完成动态内存分配和初始化工作的运算符new，以及一个能完成清理与释放内存工作的运算符delete。注意new/delete不是库函数。
3. 既然new/delete的功能完全覆盖了malloc/free，为什么C++不把malloc/free淘汰出局呢？这是因为C++程序经常要调用C函数，而C程序只能用malloc/free管理动态内存。
4. 如果用free释放“new创建的动态对象”，那么该对象因无法执行析构函数而可能导致程序出错。如果用delete释放“malloc申请的动态内存”，结果也会导致程序出错，但是该程序的可读性很差。所以new/delete必须配对使用，malloc/free也一样。

# 指针与引用的区别
1. 指针是对象，占据内存；引用是变量的别名，本身不占内存
2. `sizeof(引用)`得到的是所指对象的大小，`sizeof(指针)`得到的是指针本身大小
3. 引用必须初始化，指针不必
4. 引用初始化之后不能被改变，指针可以改变所指向的对象
5. 不存在指向空值的引用，但是存在指向指向空值的指针
6. 指针和引用的自增(++)运算意义不一样，引用++相当于引用的对象++
7. 引用是类型安全的，而指针不是（引用比指针多了类型检测）

# 指针与数组的对比
1. C++/C程序中，指针和数组在不少地方可以相互替换着用，让人产生一种错觉，以为两者是等价的。
2. 数组要么在静态存储区被创建（如全局数组），要么在栈上被创建。数组名对应着（而不是指向）一块内存，其地址与容量在生命期内保持不变，只有数组的内容可以改变。
3. 指针可以随时指向任意类型的内存块，它的特征是“可变”，所以我们常用指针来操作动态内存。指针远比数组灵活，但也更危险。

# 类的大小的计算
1. 类大小的计算遵循结构体的对齐原则，以4字节对齐
2. 类的大小与普通数据成员有关，与成员函数和静态成员无关。即普通成员函数，静态成员函数，静态数据成员，静态常量数据成员均对类的大小无影响
3. 虚函数对类的大小有影响，是因为虚函数表指针带来的影响
> 类中定义了虚函数，会在类的开始位置初始化一个VPTR，指向类的虚函数表(函数指针数组，在类定义时初始化，最后会多一个存放结束标志)，所以大小为`sizeof(指针大小) + sizeof(普通数据成员)`。注意不同的位数的编译器指针大小不同。

4. 虚继承对类的大小有影响，是因为虚基表指针带来的影响
> 注意派生类需要分配基类的存储空间，同名虚基类(virtual + class B)仅在派生类存储空间内建立一次,还需要建立一个到虚基类的偏移(指针)
> 1. 如果第一个基类没有虚函数，那么在分配完所有基类的存储空间，再分配一个VPTR指向派生类的虚函数表，再分配派生类普通数据成员的存储空间
> 2. 派生类不对基类的虚函数进行覆盖 和 派生类对基类的虚函数进行覆盖(单个VPTR)
> 3. 多继承不对基类的虚函数进行覆盖 和 派生类对基类的虚函数进行覆盖(每个含有虚函数的基类都有VPTR)

5. 空类(指的是没有定义普通数据成员的类)的大小是一个特殊情况,空类的大小为1。(new需要分配不同的内存地址，不能分配内存大小为0的空间,避免除以sizeof(T)时得到除以0错误,故使用一个字节来区分空类)
> 1. 当派生类继承空类后，派生类如果有自己的数据成员，而空基类的一个字节并不会加到派生类中去.
> 2. 一个类包含一个空类对象数据成员,空类的一个字节会加入到派生类的大小中去，记得对齐。

# 多态  
静态多态：重载函数，静态绑定  
动态多态：虚函数，动态绑定  

# 单继承多继承
1. union 既不能作为基类也不能作为派生类  
2. 缺省情况下class-private struct-public  

权限|友元是否可以访问|普通函数是否可以访问|派生类是否可以访问
-|-|-|-|
private|是|否|否
protect|是|否|是
public|是|是|是

3. `class A : public B`才构成父子关系  
>当不构成父子关系的时候，需要`A &q = *(A *) new B()`强制转换  
>当构成父子关系只需`A &p = * new B()`  

# 虚函数
1. 虚函数有隐含参数this指针，所以可以跟`const` `volatile`连用
2. `static` 没有隐含参数`this`指针，所以不能将虚函数定义为`static`，所以`virtual`不能与`static`连用
3. 类A定义虚函数vp，只能定义为类的友元，所以`virtual`不能与`friend`连用
4. 不能在`union`中定义虚函数
5. 如果基类的派生类对象分配了内存，基类和派生类的析构函数都必须定义为虚函数，不然会造成内存泄漏
6. 抽象类不能定义或产生任何对象，包括`new`， 函数返回参数，传入参数。

# 虚析构函数
这样做是为了当用一个基类的指针删除一个派生类的对象时，派生类的析构函数会被调用。  
```c++
Parent* pTest = new Child;
delete pTest;
```

# 父类指针指向子类指针时调用哪个函数
1. 父类对象和子类对象都定义了原型相同虚函数  
> 当父类指针p指向子类对象调用的是子类的函数成员  
> 当父类指针p指向父类对象调用的是父类的函数成员  

2. 父类对象和子类对象定义原型相同的函数(不是虚函数)  
> 编译的时候把父类指针指向的对象都当成父类对象，所以调用的是父类函数  

参考：  
[C++内存管理](https://www.cnblogs.com/findumars/p/5929831.html?utm_source=itdadao&utm_medium=referral)  
[c++类的大小计算](https://blog.csdn.net/fengxinlinux/article/details/72836199)  
[C++中虚析构函数的作用](https://blog.csdn.net/starlee/article/details/619827)  
