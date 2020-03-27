/*************************************************************************
    > File Name: ex_2_1.cpp
    > Author: wzy
    > Mail: 1144156906@qq.com 
    > Created Time: 2020年03月25日 星期三 17时02分22秒
 ************************************************************************/

#include <iostream>
using namespace std;

double i=2;

int main()
{
	int i=0;
	int *const p1 = &i;	//顶层，可以改值，不能改指向
	const int ci = 42;	
	const int *p2 = &ci;	//底层，可以改指向，不能改值
	const int *const p3 = p2;
	const int &r = ci;
		
	const int j=0;
	//int *const p= &j;	//error,p是顶层const指针，指针的指向是const,但是指针所指对象只是int而不是const int，这会丢失const限定符

	return 0;
}
