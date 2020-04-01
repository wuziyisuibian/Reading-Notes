# Cpp-Primer Chapter-03

**string** <br />

```
//初始化的几种方式
string s1;          //初始化一段空串
string s2(s1);      //拷贝
string s3 = s1;     //拷贝
string s4("hello"); 
string s5(10,'c');  //10个c
```
```
//string基本操作
os<<s;              //返回os
is>>s;              //以空格分割字符串，返回is
getline(is, s);     //以'\n'分割，读取一行,返回is
s.empty();
s.size();           //返回类型为string::size_type
s[n];
s1+s2;
s1=s2;
s1==s2;
s1!=s2;
<,>,<=,>=;
```
*string::size_type*是一个无符号整型，若将它和一个负值比较时，负值会被转成一个比较大的数，导致结果出现偏差；<br />

```
//#include <cctype> 对单个字符进行操作
isalnum(c);     //是否是字母或数字
isalpha(c);     //是否是字母
iscntrl(c);     //是否是控制字符
isdigit(c);     //是否是数字
isgraph(c);     //不是空格，但是可以打印时为真
islower(c);     //是否是小写字母
isprint(c);     //是否是可打印字符
ispunct(c);     //是否是标点符号（不是控制字符，数字，字母，可打印的空白）
isspace(c);     //是否是空白
isupper(c);     //是否是大写字母
isxdigit(c);    //是否是十六进制数字
tolower(c);     //转小写
toupper(c);     //转大写
```
<br />
**C++11**范围for语句<br />

```
for(auto c : str)
    cout << c << endl;

for(auto &c : str)      //&引用，可修改
    cout << c << endl;
```

## C++ STL容器
参考《STL源码剖析》<br />
STL容器即是将运用最广的一些数据结构实现出来。<br />
常用的数据结构包括array(数组), list(链表), tree(树), stack(堆栈), queue(队列), hash table(散列表), set(集合), map(映射)等，这些容器主要分为序列式容器(sequence)，关联式容器(associative)。<br />
序列式容器：array(C++内建), vector, heap(算法形式体现), priority-queue, list, slist(非标准), deque, stack(配接器), queue(配接器) <br />
关联式容器:RB-tree(非公开), set, map, multiset, multimap, hashtable(非标准), hash_set(非标准), hash_map(非标准), hash_multiset(非标准), hash_multimap(非标准);<br />

### vector
vector与array相似，差别在于空间的运用的灵活性。array是**静态空间**，一旦配置好了就不能改变，要想换大的，就需要自己一块转一块转地搬。
vector是**动态空间**，它的内部机制会自动增加空间。<br /><br />

* **vector源码：**<br />

```
//alloc是SGI STL的空间配置器，详情见《STL源码剖析》第二章
template <class T, class Alloc = alloc>
class Vector{
public:
    //vector 的嵌套型别定义
    typedef T           value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef value_type& reference;
    typedef size_t      size_type;
    typedef ptrdeff_t   defference_type;

protected:
    //以下，simple_alloc是SGI的空间配置器，见《STL源码剖析》2.2.4节
    typedef simple_alloc<value_type, Alloc> data_allocator;
    iterator start;             //表示目前使用空间的头
    iterator finish;            //表示目前使用空间的尾
    iterator end_of_storage;    //表示目前可用空间的尾

    void insert_aux(iterator position, const T& x);
    
    void deallocate() {
        if(start)
            data_allocator::deallocate(start, end_of_storage - start);
    }

    void fill_initialize(size_type n, const T& value) {
        start = allocate_and_fill(n, value);
        finish = start + n;
        end_of_storage = finish;
    }

public:
    iterator begin()            { return start; }
    oteratpr end()              { return finish; }
    size_type size() const      { return size_type(end() - begin()); }
    size_type capacity() const  { return size_type(end_of_storage - begin()); }
    bool empty() const          { return begin() == end(); }
    reference operator[](size_type n) 
                                { return *(begin() + n); }

    vector() : start(0), finish(0), end_of_storage(0) {}
    vector(size_type n, const T& value)
                                { fill_initialize(n, value); }
    vector(int n, const T& value)
                                { fill_initialize(n, value); }
    vector(long n, const T& value)
                                { fill_initialize(n, value); }
    explicit vector(size_type n)
                                { fill_initialize(n, T()); }
    
    ~vector(){
        destroy(start, finish);     //全局函数，见2.2.3节
        deallocate();               //vector的member function
    }
    
    reference front()           { return *begin(); }    //第一个元素
    reference back()            { return *(end()-1); }  //最后一个元素
    
    void push_back(const T& x) {                        //尾部插入
        if(finish != end_of_storage){
            construct(finish, x);   //全局函数，见2.2.3节
            ++finish;
        } else{
            insert_aux(end(), x);   //vector 的 member function
        }
    }
    
    void pop_back() {                                   //尾部删除
        --finish;
        destroy(finish);            //全局函数，见2.2.3节
    }   
    
    iterator erase(iterator position){                  //删除position处的元素            
        if(position+1 != end()){
            copy(position+1, finish, postion);  //后续元素往前移动
        }
        --finish;
        destroy(finish);            //全局函数，见2.2.3节
        return position;
    }
    
    void resize(size_type new_size, const T& x) {
        if(new_size < size())
            erase(begin()+new_size, end());
        else
            insert(end(), new_size-size(), x);
    }
    
    void resize(size_type new_size)
                                { resize(new_size, T()); }
    void clear()                { erase(begin(), end()); }

protected:
    //配置空间并填满
    iterator allocate_and_fill(size_type n, const T& x){
        iterator result = data_allocator::allocate(n);
        uninitialized_fill_n(result, n, x); //全局函数，见2.2.3节
        return result;
    }
};
```

*  vector迭代器

vector迭代器需要支持的操作: \*p, p->, p++, p--, p+, p-, p+=, p-=；
这些操作普通指针也能支持，所以vector的迭代器就是普通的指针，vector支持随机访问，
vector的迭代器是随机访问迭代器(Random Access Iterators)； `typedef value_type* iterator;`

* vector数据结构

线性连续空间，start和finish迭代器指向空间中已被使用的范围，end_of_storage 指向整块连续控件的尾端；
当vector内元素的数量等于空间capacity的大小时，若再新增元素，vector会自动扩容，包含三个步骤：重新分配空间，移动元素，释放原空间
















