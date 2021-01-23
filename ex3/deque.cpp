#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "deque.h"
using std::cout;
using std::cin;

template<class T> T &Deque<T>::operator[](int index)
{
    return reprarray[index];
}
template<class T> void Deque<T>::display(void)
{
    int numelements = numitems;
    int intitem;
    for (int i = 0; i < numelements; ++i)
        {
            intitem = reprarray[(head+i+1) % maxsize];
            cout << "List element " << i+1 << " is " << intitem <<".\n";
        } 
}
template<class T> void Deque<T>::pushback(int value)
{
    reprarray[rear] = value;
    rear = (rear+1) % maxsize;
    numitems++;
    if (full()) {
        allocate();
        clear();
    }
}
template<class T> void Deque<T>::pushfront(int value)
{
    reprarray[head] = value;
    head = (head+maxsize-1) % maxsize;
    numitems++;
    if (full()) {
        allocate();
        clear();
    }
}

template<class T> void Deque<T>::popback(void)
{
    if (empty()) {
        cout << "Error! The list is empty.\n";
        return;
    }
    rear = (rear-1) % maxsize;
    reprarray[rear] = 0;
    numitems--;
    if (less()) {
        deallocate();
        clear();
    }
}

template<class T> void Deque<T>::popfront(void)
{
    if (empty()) {
        cout << "Error! The list is empty.\n";
        return;
    }
    head = (head+1) % maxsize;
    reprarray[head] = 0;
    numitems--;
    if (less()){
        deallocate();
        clear();
    }
}

template<class T> void Deque<T>::allocate()
{
    int newsize = 2 * maxsize;
    int *newarray = new int[newsize];
    for (int i = 1; i <= numitems; ++i)
    {
        newarray[i] = reprarray[(head+i) % maxsize];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void Deque<T>::deallocate()
{
    int newsize = maxsize / 2;
    int *newarray = new int[newsize];
    for (int i = 1; i <= numitems; ++i)
    {
        newarray[i] = reprarray[(head+i) % maxsize];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return; 
}
template<class T> bool Deque<T>::full()
{
    if ((head+maxsize-1) % maxsize == rear)
    {
        return true;
    }
    return false;
}

template<class T> bool Deque<T>::empty()
{
    if ((head+maxsize+1) % maxsize == rear)
    {
        return true;
    }
    return false;
}

template<class T> bool Deque<T>::less(void)
{
    if((numitems+2)==maxsize/4 && maxsize>20)
    {
        return true;
    }
    return false;
}

template<class T> int Deque<T>::getlength(void)
{
    return numitems;
}

template<class T> int Deque<T>::getmaxsize(void)
{
    return maxsize;
}

template<class T> void Deque<T>::clear(void)
{
    head = 0;
    rear = numitems+1;
}

