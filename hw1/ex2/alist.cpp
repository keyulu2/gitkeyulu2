//
//  alist.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.h"
using std::cout;
using std::cin;



template<class T> T &AList<T>::operator[](int index)
{
    return reprarray[index - 1];
}

template<class T> int AList<T>::getlength(void)
{
    return numitems;
}

template<class T> void AList<T>::setitem(int index, T value)
{
    if ((index > 0) && (index <= numitems))
    {
        reprarray[index - 1] = value;
        return;
    }
    else
        cout << "Index error: index out or range\n";
}

template<class T> T AList<T>::getitem(int index)
{
    if ((index > 0) && (index <= numitems))
    {
        return reprarray[index - 1];
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void AList<T>::append(T value)
{
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
}

template<class T> void AList<T>::insert(int index, T value)
{
    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems - 1; j >= index; --j)
        {
            reprarray[j+1] = reprarray[j];
        }
        reprarray[index] = value;
        ++numitems;
        return;
    }
    else
    {
        append(value);
        return;
    }
}

template<class T> void AList<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::remove(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index <= numitems)
    {
        for (int j = index; j < numitems; ++j)
        {
            reprarray[j-1] = reprarray[j];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
}

template<class T> void AList<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::concat(AList<T> &list)
{
    int length = list.getlength();
    for (int i = 1; i <= length; ++i)
    {
        append(list[i]);
    }
    return;
}

template<class T> bool AList<T>::member(T value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i] == value)
        {
            result = true;
            break;
        }
    }
    return result;
}

template<class T> bool AList<T>::equal(AList<T> &list)
{
    bool result = true;
    if (numitems == list.getlength())
    {
        for (int i = 0; i < numitems; ++i)
        {
            if (reprarray[i] == list[i + 1])
                continue;
            else
            {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
}

template<class T> bool AList<T>::sublist(AList<T> &list)
{
    int length = list.getlength();
    bool result = true;
    for (int i = 1, j = 0; (i <= length) && (j < numitems); ++i, ++j)
    {
        if (list[i] == reprarray[j])
        {
            if ((j == numitems - 1) && (i < length))
            {
                result = false;
                break;
            }
        }
        else
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
                --i;
    }
    return result;
}



template<class T> int AList<T>::src_length(AList<T> l)
{
    int number=l.getlength();
    if (0==number){
        return 0;
    }
    else if (1==number)
    {
        return 1;
    }
    int mid = number/2;
    AList<T> list1=AList<T>(mid);
    AList<T> list2=AList<T>(number-mid);
    for (int i=0; i<number; i++){
        if(i<mid){
            list1.append(l.reprarray[i]);
        }
        else{
            list2.append(l.reprarray[i]);
        }
    }
    return src_length(list1)+src_length(list2);
}

template<class T>  void AList<T>::src_apply(T (*function_f)(T), AList<T>& l)
{
    int number=l.getlength();
    if (0==number){
        return;
    }
    else if (1==number)
    {
        l.reprarray[0]=function_f(l.reprarray[0]);
        return;
    }
    int mid = number/2;
    AList<T> list1=AList<T>(mid);
    AList<T> list2=AList<T>(number-mid);
    for (int i=0; i<number; i++){
        if(i<mid){
            list1.append(l.reprarray[i]);
        }
        else{
            list2.append(l.reprarray[i]);
        }
    }
    src_apply(function_f,list1);
    src_apply(function_f,list2);
    list1.concat(list2);
    l=list1;
    return;
}


template<class T> void AList<T>::src_condition(T (*condition)(T),AList<T>& l)
{
    int number=l.getlength();
    if (0==number){
        return;
    }
    else if (1==number)
    {
        if (0 == condition(l.reprarray[0])){
            l.remove(1);
        }
        return;
    }
    int mid = number/2;
    AList<T> list1=AList<T>(mid);
    AList<T> list2=AList<T>(number-mid);
    for (int i=0; i<number; i++){
        if(i<mid){
            list1.append(l.reprarray[i]);
        }
        else{
            list2.append(l.reprarray[i]);
        }
    }
    src_condition(condition,list1);
    src_condition(condition,list2);
    list1.concat(list2);
    l=list1;
    return;
}