#ifndef QH_VECTOR_H_
#define QH_VECTOR_H_
#include<iostream>

namespace qh
{

    const int MaxCapacity=100;
    template<class T>
    class vector {

    private:
        T*      data_;
        size_t  size_;
        size_t  capacity_;

    public:
        //ctor
        vector(): data_(NULL), size_(0),capacity_(0){};

        explicit vector(size_t , const T&);

        vector<T>& operator=(const vector<T>& );

        //dtor
        ~vector()
        {
            if (data_){
                delete [] data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        size_t getCapacity(){
            return capacity_;
        }

        // set & get
        T& operator[](size_t index){
            return data_[index];
        }

        // set
        //insert element
        void push_back(T);

        //pop element from the end of the array
        void pop_back();

        //change the vector size to newSize
        void resize(int );

        //reassign the vector
        void reserve(int);

        //don't know how to implemnt the function
        void clear();

        //judge if the vector is empty
        bool  empty();

        //return the last element of the vector
        const T back();
        typedef  T* iterator;
        typedef  const T* const_iterator;
        iterator begin(){
            if(!empty())
                return &data_[0];
            else{
                std::cout<<"empty vector!!!"<<std::endl;
                return 0;
            }
        };

        const_iterator begin() const
        {
            if(!empty())
                return &data_[0];
            else{
                std::cout<<"empty vector!!!"<<std::endl;
                return 0;
            }
        };

        iterator end(){
            if(!empty())
                return &data_[size()];
            else{
                std::cout<<"empty vector!!!"<<std::endl;
                return 0;
            }
        }

        const_iterator end() const
        {
            if(!empty())
                return &data_[size()];
            else{
                std::cout<<"empty vector!!!"<<std::endl;
                return 0;
            }
        }

        void print(){
            std::cout<<"The Size of the vector:"<<size_<<std::endl;
            std::cout<<"The capacity of the vector:"<<capacity_<<std::endl;
            std::cout<<"The elements of the vector:"<<std::endl;
            iterator item=begin();
            while((item)!=end()){
                std::cout<<*item<<" ";
                item++;
            }
             std::cout<<std::endl;
        }
    };
}


#endif


