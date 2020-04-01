# Cpp-Primer Chapter-02

C++是一种**静态数据类型语言**，类型检查发生在编译时。**动态数据类型语言**是指类型检查发生在运行时。<br /><br />

算术类型分为两类：**整型**和**浮点型**<br /><br />

**初始化**与**赋值**的区别：<br />
初始化调用**拷贝构造**函数，赋值调用**赋值运算符**函数。未被初始化就**调用默认构造**函数，内置类型，在函数体外默认初始化为0，函数体内**不被初始化**。<br /><br />

**声明**和**定义**的区别：<br />
声明使得名字被程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。而定义负责创建与名字关联的实体。<br />
如果想仅仅声明而不定义变量，需加上**extern**。函数体内外都可以使用*extern*，但是，在函数体内使用*extern*时，若初始化，编译时会报错。 <br /><br />

**Google变量命名规范**：<br />

* 命名需具有描述性，少用缩写
* 类，结构体，类型定义(typedef)，枚举，模板参数类型，每个单词的首字母均大写，不包含下划线

```
// 类和结构体
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...

// 类型定义
typedef hash_map<UrlTableProperties *, string> PropertiesMap;

// using 别名
using PropertiesMap = hash_map<UrlTableProperties *, string>;

// 枚举
enum UrlTableErrors { ...
```

* 变量 (包括函数参数) 和数据成员名一律小写, 单词之间用下划线连接. 类的成员变量以下划线结尾, 但结构体的就不用, 如: `a_local_variable`, `a_struct_data_member`, `a_class_data_member_`。
* 常量以k开头，大小写混合`kDaysInWeek`。
* 函数名，首字母大写，对于首字母缩写的单词，视作一个单词`StartRpc()`。
* 命名空间以小写字母，一般是项目或者团队的名字。
* 宏，全部大写加下划线`MY_HOME_BORING`。

### 引用
右值引用留到13章，一般说引用其实指的是左值引用。<br />
使用：`int &ref_val = val;`<br />
引用必须初始化；引用不是对象。引用所绑定的对象不可更改；<br />
**non-cosnt 左值引用不能绑定到右值**

### 指针
指针是一个对象，允许赋值和拷贝，指针无需初始化。<br />
使用：`int *p = &i;` <br />
使用指针时需判断是否为空指针`nullptr NULL 0`,建议**初始化所有指针**，以免产生预料之外的错误。

### const限定符
const对象必须**初始化**。<br /> <br />

**混合情况**：
* 指向指针的引用`int *&r=p`
* const的引用

```
const int i = 1024;
const int &ri = i;
```
```
int i = 42;
const int &r2 = i;	//const修饰引用，表示在对引用进行操作时，把引用绑定的对象当作const，但是直接对这个对象进行操作时，引用的const属性并不会对这个对象造成约束；
const int &r3 = 42;	//常量是右值，const lvalue reference可以绑定到右值
const int &r3  = 4.2;		//同理，先创建一个临时int变量，r3再绑定到该右值

const int j=0;
int &k=j;	//error，non-const reference绑定到const 会丢失const限定符
```

* 指针和const

```
const double pi = 3.14;
double *ptr = &pi;	//error，会丢失const限定符
const double *ptr = &pi;	//const指针可以指向常量
double p2=3.14;
ptr = &p2;	//const指针可以指向非常量
```
```
int err_num = 0;
int *const cur_err = &err_num;	//表示cur_err指向err_num的关系是常量，仍然可以通过该指针修改所指对象
const double *p = &err_num;	//错误，指针类型需严格匹配
```

* 顶层与底层const<br />
就指针来说，指针的本质是指针，当const修饰的是这个本质时，这就是个顶层const，修饰指针所指对象是个const int时，这便是个底层cosnt；`int *const p=&i;`，这是顶层；`const int *p = &i;`，这是一个底层const；<br />
因为引用本身的性质决定了，不可更改绑定的对象，所以const 引用，都是底层引用；

```
int i=0;
int *const p1 = &i;	//顶层，可以改值，不能改指向
const int ci = 42;	
const int *p2 = &ci;	//底层，可以改指向，不能改值
const int *const p3 = p2;
const int &r = ci;
	
const int j=0;
int *const p= &j;	//error,p是顶层const指针，指针的指向是const,但是指针所指对象只是int而不是const int，这会丢失const限定符
```
<br />

**常量表达式** <br />
在编译时就确定结果，且运行过程也绝不改变值。这需要满足两个条件，其一，初始值在编译时就是一个确定的值；第二，数据类型是const的话，确保运行过程中不会被改变。<br /> <br />

**constexpr**<br />
待补充<br /><br />

**类型别名**<br />

* `typedef double wages;`
* `using SI = SalesItem;`<br /> <br />

**auto类型说明符**<br />
会丢失顶层const，保留底层const,丢失&。
```
const int i=0, &r = i;
auto j = i;	//j只是个int
const auto k = i;	//k是const int
auto h = r;	//h只是一个int,而不是引用类型
auto &h=r;	//这样才能得到一个引用
cosnt int *const p = &i;	
auto ptr = p;	//ptr指向常量对象，但不是指针常量
```
<br />

**decltype类型指示符**<br />
与auto不同，保留顶层const和&引用属性。<br />
```
const int ci = 0, &cj = ci;
decltypr(ci) x = 0;	//const int
decltype(cj) y = x;	//const in&
decltype(cj) z;		//error, 引用必须初始化
```
<br />

### 自定义数据结构
SalesData<br />
```
typedef struct SalesData{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
} SData;
```

















