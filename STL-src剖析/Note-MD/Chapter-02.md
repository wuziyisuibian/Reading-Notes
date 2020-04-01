# STL-Src Chapter-02

**空间配置器的标准接口** <br />
```
allocator::value_type;
allocator::pointer;
allocator::const_pointer;
allocator::reference;
allocator::const_reference;
allocator::size_type;
allocator::difference_type;

allocator::rebind;  //模板类是类模板实例化的产物
    //这是一个嵌套的类模板(class template)，class rebind<U>拥有唯一成员other，这是一个typedef，代表allocator<U>；
allocator::allocator();
allocator::allocator(const allocator&);
template <class U>allocator::allocator(const allocator<U>&);
allocator::~allocator();
pointer allocator::address(reference x) const;
    //返回某个对象的地址，a.addresss(x)等同于 &x
const_pointer allocator::address(const_reference x) const;
pointer allocator::allocate(size_type n, const void *=0);
    //配置空间，足以存储n个T对象，第二参数是个提示。实现上会利用它来增进区域性(locality)，或者完全忽略
void allocator::deallocate(pointer p, size_type n);
    //归还先前配置的空间
size_type allocator::max_size() const;
    //返回可成功配置的最大量
void allocator::construct(pointer p, const T& x);
    //等同于new(const void*) p) T(x)
void allcator::destroy(pointer p)
```














