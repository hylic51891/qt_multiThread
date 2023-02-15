# QT多线程学习

## 基础知识

[**基础知识介绍**](https://www.cnblogs.com/jmsjh/p/7762034.html) : 多线程逻辑

**进程**：是一个正在执行中的程序，每一个进程执行都有一个执行顺序，这个顺序是一个执行路径，或者叫一个控制单元。确切的来说，当一个程序进入内存运行，即变成一个进程，进程是处于运行过程中的程序，并且具有一定独立功能。

**线程**：进程中的一个独立控制单元，一个进程中至少有一个线程，可以包含多个线程

## 建立QT多线程的方法

### 三种方法

* 继承Qthread类重写run()函数
* 继承QObject的moveToThread多线程实现
* 使用QThreadPool实现多线程

### 参考案例  

<https://blog.csdn.net/iriczhao/article/details/123057360> ：【QThreadPool 】线程池  
<https://blog.csdn.net/qq_37529913/article/details/115536799> ： QT 多线程之线程池QThreadPool(深入理解)
<https://blog.csdn.net/tjcwt2011/article/details/111300735> ：QT线程池的源码解读和示例：说明可以在for循环中创建线程  
<https://blog.csdn.net/lengyuefeng212/article/details/119816756> ：两个基础例子实现QT的多线程
<https://blog.csdn.net/zong596568821xp/article/details/78893360> ：介绍两种多线程创建方法以及优劣  
<https://blog.csdn.net/qq_37529913/article/details/115536799> ：建立的例子  

### QT线程锁

<https://blog.csdn.net/wj584652425/article/details/123832801> 读写锁（QReadWriteLock）的使用、读写锁的验证（含源码+注释）  
<https://blog.csdn.net/wj584652425/article/details/123585126QT> 互斥锁  
https://blog.csdn.net/qq_43680827/article/details/128785606 互斥锁和读写锁比较  

### QT线程通信

<https://blog.csdn.net/hebbely/article/details/79428336> 传自定义参数先用 qRegisterMetaType来定义

    模板为**qRegisterMetaType<自定义参数/结构/类>("自定义参数/结构/类");**，比如定义abfThread的静态结构参数G_ABFTableSrcUnit，使用`qRegisterMetaType<abfThread::G_ABFTableSrcUnit>("abfThread::G_ABFTableSrcUnit");`
