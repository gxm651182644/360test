#include <stdlib.h>
#include "qh_vector.cc"
using std::cout;
using std::endl;


void test1(){
    /*���и�����Ա�����Ĳ��ԣ������ǰvector��size_��capacity_
    *�Լ������Ԫ��
    */
    qh::vector<int> num_vect;
    qh::vector<int> num_vect1(10,1);
    qh::vector<int> num_vect2;
    qh::vector<int> num_vect3;

    cout<<"Ĭ�ϳ�ʼ��-->vector()"<<endl;
    num_vect.print();//���Գ�ʼ��1

    cout<<"��ʼ��--> vector(size_t , const T&)"<<endl;
    num_vect1.print();//���Գ�ʼ��2

    cout<<"��ֵ��ʼ��-->operator=(const vector<T>& )"<<endl;
    num_vect2=num_vect1;
    num_vect2.print();//���Ը�ֵ����

    cout<<"����push_back()����"<<endl;
    for(int i=0;i<5;i++)
    {num_vect3.push_back(i);}
    num_vect3.print();//push����

    cout<<"����pop_back()����"<<endl;
    num_vect3.pop_back();
    num_vect3.pop_back();
    num_vect3.print();//pop_back����

    //num_vect3.resize(20);
    //num_vect3.print();//resize����
    cout<<"����reserve()����"<<endl;
    num_vect3.reserve(30);
    num_vect3.print();//resize����

}
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

    test1();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}

