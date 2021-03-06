#include<iostream>

using namespace std;

//测试大小端的问题
//大端模式：是将高字节存入到低地址中，将低字节保存到高地址之中，这样做像是字符串的顺序处理一样
//          地址由小到大，数据由高到低
//小端模式：是将高字节存入到高地址中，低字节保存到低地址中，这种模式将地址的高低和数据位有校的结合
 //         高地址的部分权位高，低地址的部分权位低
int main()
{
	int i = 1;
	char j = *(char*)(&i);
	if (j == 1)
		printf("小端模式\n");
	else
	    printf("大端的模式\n");
	return 0;
}

//C和C++的区别？

//1.C语言是面向过程的，C++是面向对象
//面向过程：主要是将问题分解成一个一个的步骤，根据这些步骤，来进行一个一个解决
//面向对象：是将这一个问题分解成各个对象，这些对象不是为了解决某个问题，而是为了描述在整体的一个行为
//2.C语言是不支持重载的，C++支持重载
//3.C语言不支持默认值，C++语言支持默认值

//程序运行的过程？
//1.预处理   主要任务是条件编译 头文件  宏替换 去掉注释 
//2.编译     将预处理后的文件，转化为汇编语言
//3.汇编	 将汇编语言转化为机器可识别的目标代码
//4.链接	 将目标代码生成可执行程序

//内存分布的方式？
//1.在栈上  栈上修饰的变量只在调用时期存在局部变量，好处是栈上分配的资源调用速度快，效率高，坏处是分配的资源有限
//2.在堆上(动态存储区出面)    像是malloc/free在堆上申请，可以根据申请者的需要，开辟大空间，方便，但是问题也很多
//3.在静态存储区上存储   指的整个程序运行期间都存在，比如说是全局变量，static修饰的变量

//struct 和 union 的区别？
//1.在存放多个数据成员的时候，struct会给每一个数据成员都分配一个空间，但是union只会分配空间一个空间，存储最后一位数据成员的信息
//2.都有不同类的数据成员，但在任意是个，union只存放了被选中的成员信息，而struct存放了所有的成员信息
//3.两者都是会内存对齐的，struct还是和之前一样内存对齐，union会根据占用字节数的来进行内存对齐

//static 和 const 的区别？
//1.static
//
//
//指针和数组的区别？
//1.指针就是指针，在32位平台下面占用4个字节，在64位平台上，占用8个字节，其值表示某一个内存的地址
//2.数组，就是有类型和个数组成，在创建数组的时候，要说明他的类型和个数，数组可以存放任意类型，但是不能存放函数
//3.联系：数组在一定的情况下，可以转化为指针。当数组在表达式中使用的时候，编译器就将数组转化为指针，指向第一个元素的地址

//指针和引用的区别？
//1.指针：与上相同
//2.引用：是指针的别名 a.理论上来说，指针的级数没有限制，但是引用只有一级
//					   b.指针在运行期间可以改变它所指向的对象，但是引用不能，他在程序运行之前，就已经和某个对象绑定好了，不能在改变，但是内容可以改变
//					   c.程序为指针变量分配内存，但是不为引用分配内存，引用声明时必须要初始化，从而指向一个已近存在的对象，不能指向空值


//为什么要内存对齐？
//1.平台原因，不是所有的平台都可以任意访问数据，有的平台会访问特定内存上的数据，导致无法查看，会抛异常
//2.效率问题，数据结构的时候应该边界内存对齐，如果不对齐，我们对于访问的有些数据会访问两次，对齐的话，只需要访问一次，提高效率，但是浪费了内存空间

//C语言中的结构体和C++中的结构体
//1.C语言中的结构体只能定义成员变量，不能定义函数。 C++中可以定义成员变量也可以定义成员函数函数
//2.C语言结构体中struct不能省略，但是C++中可以
//3.C语言结构体为NULL的话，会报错

//C++

//C++中结构体和类的区别？
//1.主要是在访问权限中的区别，结构体中的成员函数对外默认继承是public类型的，但是类中的默认继承访问权限是私有的

//数组和链表的区别？
//1.数组支持随机访问，查找的速度快，时间复杂度为O(n); 链表是以节点的方式存储，不支持随机访问
//2.数组插入和删除的时候，效率比较低； 链表的插入和删除的效率高
//3.数组的插入需要开辟更大的空间，空间的利用率比较低；链表的空间利用率高，插入一个数据，开辟一个空间
//4.数组的大小固定，不能拓张；链表的大小不固定，可以动态开辟

//顺序表和链表的区别？
//1.顺序表支持随机访问 ，链表不支持随即访问
//2.顺序表的删除和插入的效率低，链表的效率高
//3.顺序表的不能动态开辟，内存的利用率低，链表支持动态开辟，内存的利用率高

//vector和list的区别？
//1.vector的底层为顺序表，支持随机访问  list的底层为带头的双向链表，不支持随机访问
//2.vector进行插入和删除的时候效率低 插入还会开辟新的空间，拷贝/释放旧的空间，    list的插入和删除的时候效率高
//3.vector再插入和删除的时候，都会导致迭代器失效，插入可能导致扩容，只是原来的迭代器失效，删除时，当前迭代器需要重新符值，否则失效
//  list在插入到时候没有迭代器失效的问题，在删除的时候，没有对当前的的迭代器符值的话，只失效当前的迭代器，其他的不受影响

//红黑树和AVL树的区别？
//红黑树不需要保持绝对的平衡，只需要保持最长路劲不超过最短路径的2倍，这样子就减低的插入和旋装的次数，所以经常在
//插入或者删除的时候比AVL树更优。但是AVL树他是高度不差1，绝对的平衡，所以在删除元素之后，最坏的情况是，将新的node
//和这条路径上的所有节点都旋装一遍，时间复杂度很高。而红黑树只需要旋装3次，O(1),而且红黑树比AVL树更好实现，实际更
//多的情况下面使用的是红黑树

//set和map的区别？

//malloc/free和new/delete的区别？
//1.malloc/free和new/delete共同点是：都是由堆上申请的，并且需要手动释放
//2.malloc/free是函数，new/delete是操作符
//3.malloc申请空间失败会返回NULL，因此使用的时候需要判空  new不需要，但是需要捕获异常
//4.malloc的返回值为(viod*),在使用是时候需要强转，new不需要，因为new后面跟的是空间类型
//5.malloc申请的空间不会初始化，但是new申请的会初始化
//6.申请自定义类型的时候，malloc/free只会开辟空间，不会调用构造和析构函数，但是new/delete会调用，new在申请空间的
//的时候会调用构造函数，delete在释放的时候，会调用析构函数，完成资源的清理

//什么是内存泄漏？怎么防止内存泄漏？
//1.内存泄露指的是当我们疏忽或者运行错误的程序未能释放已经不再使用的资源了，内存泄漏指的不是我们所说的物理上的消失
//而是当应用程序分配了一段资源之后，因为设计错误，我们不能在对这块资源进行控制了，因而造成内存的浪费了

//1.确保没有访问空指针
//2.每个内存分配函数之后都要调用free的函数与之对应
//3.每次进行分配空间之后  都应该及时进行初始化
//4.始终正确的处理返回动态分配内存的引用函数的返回值


//Linux中复习
//一些基础的命令
//ls/pwd/cd/gdb/ps/man/vim/mkfile/等基础命令
//pwd 显示当前用户所在的目录

//gdb 进入调试 
//打断点 b+行数
//删除断点  d+行数
//查看断点 info + b
//让程序跑起来 r
//进入程序 s
//把当前的循环跑完  finsh
//单行显示  n
//直接跳转的第几行 until+行数
//当第一行只有一个断点的向下运行时，卡住了，如果想继续向下走，按c
//退出 quit

//mkfile
//
//进程和线程的区别
//进程间的一些通信方式
//线程之间的一些通信方面
//怎么产生死锁，怎么解决死锁



