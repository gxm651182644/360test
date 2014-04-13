#include<iostream>
#include"qh_vector.h"
namespace qh{

template<class T>
vector<T>::vector( size_t n, const T& value = T())
{
    data_ = new T[n];
    capacity_=n+MaxCapacity;
    size_=n;
    for (size_t i = 0; i < n; i++)
    {
        data_[i] = value;
    }
}

template<class T>
vector<T>&  vector<T>::operator=(const vector<T>& rhs)
{
   if(this!=&rhs){
        delete [] data_;
        size_=rhs.size();
        capacity_=rhs.capacity_;

        data_=new T[capacity_];
        for(int k=0;k<size_;k++){
            data_[k]=rhs.data_[k];
        }
    }
    return *this;
}

template<class T>
void vector<T>::push_back(T element){
    if(size_==capacity_){
        reserve(2*capacity_+1);
    }
    data_[size_++]=element;

}

 template<class T>
 void vector<T>::pop_back(){
    size_--;
 }

template<class T>
void vector<T>::resize(int newSize){
    if(newSize>capacity_)
        reserve(newSize*2+1);
    size_=newSize;
}

template<class T>
void vector<T>::reserve(int newCapacity){
    if(newCapacity<size_)
        return;
    T*oldarray=data_;
    data_=new T[newCapacity];
    for(int k=0;k<size_;k++){
       data_[k]= oldarray[k];
    }
    capacity_=newCapacity;
    delete [] oldarray;

}

template<class T>
void vector<T>::clear(){
 //不知道如何实现
}

template<class T>
bool  vector<T>::empty(){
    return size_==0;
}

template<class T>
const T vector<T>::back(){
    if(!empty())
        return data_[size_-1];
}
}
