# Cpp-Primer Chaptor-01

### 1.1 编写一个简单的C++程序
函数包含四个部分：<br />

* 返回类型*(return type)*
* 函数名*(function name)*
* 形参列表*(parameter list)*
* 函数体*(function body)*

linux系统编译指令`g++ xx.cpp -o a.out -I /include` <br />
查看上一个运行完程序的返回值`echo $?` <br />
输入输出`cin cout cerr clog` <br />
读取数量不定的输入`while (cin >>value)`当遇到文件结束符或者无效输入时**istream**的状态会变为无效。Linux通过Ctrl+D输入文件结束符。