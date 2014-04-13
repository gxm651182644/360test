#include <stdlib.h>
#include "qh_vector.cc"
using std::cout;
using std::endl;


void test1(){
    /*进行各个成员函数的测试，输出当前vector的size_和capacity_
    *以及里面的元素
    */
    qh::vector<int> num_vect;
    qh::vector<int> num_vect1(10,1);
    qh::vector<int> num_vect2;
    qh::vector<int> num_vect3;

    cout<<"默认初始化-->vector()"<<endl;
    num_vect.print();//测试初始化1

    cout<<"初始化--> vector(size_t , const T&)"<<endl;
    num_vect1.print();//测试初始化2

    cout<<"赋值初始化-->operator=(const vector<T>& )"<<endl;
    num_vect2=num_vect1;
    num_vect2.print();//测试赋值函数

    cout<<"测试push_back()函数"<<endl;
    for(int i=0;i<5;i++)
    {num_vect3.push_back(i);}
    num_vect3.print();//push函数

    cout<<"测试pop_back()函数"<<endl;
    num_vect3.pop_back();
    num_vect3.pop_back();
    num_vect3.print();//pop_back函数

    //num_vect3.resize(20);
    //num_vect3.print();//resize函数
    cout<<"测试reserve()函数"<<endl;
    num_vect3.reserve(30);
    num_vect3.print();//resize函数

}
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

    test1();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}

