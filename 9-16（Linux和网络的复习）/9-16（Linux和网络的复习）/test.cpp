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
//$@sum(目标文件)  $^sum.c(依赖文件)   
//.PHONY:clean   生成伪目标  总是被执行的
//为什么设置clean为伪目标，  那是因为我们要保持每次运行都是可执行的
//make是怎么判断他需要执行的，是由时间判断的，每次编译都是有时间的，每次编译都是查看时间的，为什么PHONY总是
//被执行，那是因为他不查看时间执行，所以总是被执行

//进程和线程的区别？
//1.进程是拥有系统资源的基本单位，线程是系统调用和分配的基本单位
//2.进程的创建和消除一个进程需要消耗内存的空间比较大 线程因为是相互的，所以消耗的内存比较小
//3.进程之间是相互独立啊，不会因为一个进程的崩溃，导致程序崩溃，而线程没有独立的地址空间，一个 崩溃，导致整个线程崩溃
//两者之间的联系
//1.一个线程对应只有一个进程，但是一个进程拥有多个线程
//2.系统分配资源给进程，同一个进程中的线程共享该进程的所有资源
//3.不同进程间的线程通过消息队列完成同步

//进程间的一些通信方式？
//信号量：主要是对临界资源的一个保护
//管道：我们把一个进程链接到另外一个进程的过程叫做管道。特点：a.面向字节流的，b.单项流通的，c.生命周期随内核，d.
//消息队列：底层可以认为是一个全部链表，主要存放他的类型和内容，使用标识符标记。可实现双向流通
//共享内存：不用由用户态到内核态的频繁切换或者相互转化，直接由内存中调取使用就可以，他是临界资源，使用时要保证他的原子性

//线程之间的一些通信方面？
//1.锁机制，互斥锁，条件变量，读写锁
//a.互斥锁提供了以他的其他方式排斥了互斥锁的并发进行
//d.条件变量，主要是以原子的方式进行一个阻塞排斥
//c.读写锁可以允许多个线程同时共享内存，而对写的操作是互斥的
//2.信号量机制
//3.信号机制  对临界资源的保护

//什么是死锁，怎么产生死锁，怎么解决死锁，怎么避免死锁？
//1.指的是两个或者两个以上的进程在执行的过程，相互对一块资源进行相互争夺的而造成的一种阻塞现象，在无外力的作用下
//，他们都无法进行下去，此使系统处在死锁的状态或者系统产生死锁。
//2.互斥条件，请求与保持条件/不可剥夺条件/循环等待条件
//互斥条件：指的是一块资源只能同时被一个线程访问，其他线程不能被访问，直到这个资源被释放， 通俗来说：就是我加了锁被人不能加
//请求与保持条件：指的是现在有一快资源被一个线程请求并且加锁了，现在又来了一个线程请求，但是资源被占用，有对自己的资源不释放：通俗来说就是吃着碗里面的，看着锅里面
//不可剥夺条件：线程已近获得了这块资源，并且加了锁，其他的资源想要进来剥夺，是不行的，通俗来讲：我自己锁别人不能解锁
//循环等待条件：发生死锁时，队列的循环链，比如收队列p0..pn,p0等待p1占用的资源，...pn等待p0占用的资源

//3.只要破坏上面的任意一个就可以，因为互斥条件是非共享资源所必须的，所以这个不能修改
//a.请求与保持条件;可以当一块资源进行请求并且加锁之后，另外一块资源想要访问的时候，可以等待，直到另外一个释放
//b不可剥夺条件：当一个资源申请了一块空间的时候，另外一个资源只能等待这个资源释放之后，才能申请
//c循环等待条件：实现资源的分配原则，对资源进行编号，按照序号进行资源的访问

//1.加锁的顺序
//2.加锁的时间
//3.死锁的检测
//4.银行家算法1.当一个顾客来借钱不超过银行现有的资金就可以容乃顾客。可以分期贷款，放贷的时候，不能超过现有的资金
//			  顾客来借款的时候，可以推迟借款，最后可以在时间内给顾客分钱，最后顾客拿到钱，在有限的时间内还钱就可以了

//网络基础的复习

//当输入一个网址的时候，回车之后经过什么过程？

//OS的七层结构
//TCP和UDP的区别
//三次握手，四次挥手
//http和https






