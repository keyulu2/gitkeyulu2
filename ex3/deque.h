#ifndef deque_h
#define deque_h

template<class T> class Deque
{
public:
    Deque(int size = 20);
    void pushback(int index);
    void pushfront(int index);
    T &operator[](int index);
    void popback(void);
    void display(void);
    void popfront(void);
    int getlength(void);
    int getmaxsize(void);
    int get(int index);
    int head = 0;
    int rear = 1;
private:
    int maxsize, minsize;
    int numitems;
    T *reprarray;
    void allocate(void);
    void deallocate(void);
    bool full(void);
    bool empty(void);
    bool less(void);
    void clear(void);
};

template<class T> Deque<T>::Deque(int size)
{
    maxsize = size;
    if (size < 20)
        minsize = size;
    else
        minsize = 20;
    numitems = 0;
    reprarray = new T[maxsize];
}

#endif