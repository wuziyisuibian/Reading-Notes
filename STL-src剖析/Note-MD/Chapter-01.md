# STL-Src Chapter-01

**STL六大组件** <br />
* 容器(containers)：各种数据结构；
* 算法(algorithms)；
* 迭代器(iterators)：容器和算法的胶合剂，所谓的泛型指针；
* 仿函数(functors)；
* 适配器(adapters)；
* 空间配置器(allocators)；<br />
  相互关系：Container通过Allocator获得数据储存空间，Algorithm通过Iterator存取Container内容，Functor可以协助Algorithm完成不同的策略变化，Adapter可以修饰或套接Functor。<br /><br />




