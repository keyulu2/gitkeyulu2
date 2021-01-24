//
//  alist.h
//
//
//  Created by KD on 14.01.21.
//

#ifndef alist_h
#define alist_h
#include <variant>
template<class T> class AList;

typedef int* (AList<int>::*pClassFun2)(int*, int*);
typedef int* (AList<int>::*pClassFun1)(int*);
template<class T> class AList
{

public:
    AList(int size = 20);
//    virtual ~AList();
    T &operator[](int index);
    int getlength(void);
    void setitem(int index, T value);
    T getitem(int index);
    void append(T value);
    void insert(int index, T value);
    void remove(int index);
    void concat(AList<T> &list);
    bool member(T value);
    bool equal(AList<T> &list);
    bool sublist(AList<T> &list);
    
    int src_length(AList<T> l);
    void src_apply(T (*function_f)(T), AList<T>& l);
    void src_condition(T (*condition)(T),AList<T>& l);


private:
    int maxsize, minsize;
    int numitems;
    T *reprarray;
    void allocate(void);
    void deallocate(void);
};

template<class T> AList<T>::AList(int size)
{
    maxsize = size;
    if (size < 20)
        minsize = size;
    else
        minsize = 20;
    numitems = 0;
    reprarray = new T[maxsize];
}

//template<class T> AList<T>::~AList()
//{
//    delete[] reprarray;
//}

#endif /* alist_h */