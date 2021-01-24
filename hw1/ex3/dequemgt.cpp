
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "deque.cpp"
using std::cout;
using std::cin;

int main()
{  
    int op;
    int size = 20;
    int item;
    int intitem;
    Deque<int> mylist;
    do
    {
        do{
            cout << "Choose an operation:\n";
            cout << "0: quit\n";
            cout << "1: pushback\n";
            cout << "2: pushfront\n";
            cout << "3: popback\n";
            cout << "4: popfront\n";
            cout << "5: display\n";
            cout << "6: the output of test case, please press it at the beginning when grading it\n";
            cin >> op ;
        }
        while  ((op < 0) || (op > 6));

        switch (op)
        {
            case 0: break;
            case 1:
            {
                cout << "Enter a value:\n";
                cin >> item;
                mylist.pushback(item);
                break;
            }
            case 2:
            {
                cout << "Enter a value:\n";
                cin >> item;
                mylist.pushfront(item);
                break;
            }
            case 3:
            {
                mylist.popback();
                break;
            }
            case 4:
            {
                mylist.popfront();
                break;
            }
            case 5:
            {
                int numelements = mylist.getlength();
                int head = mylist.head;
                for (int i = 0; i < numelements; ++i)
                {
                    intitem = mylist[++head % size];
                    cout << "List element " << i << " is " << intitem <<".\n";
                }
            }
            case 6:
            {
                cout<< "successful case:\n";
                cout << "pushback 1\n";
                mylist.pushback(1);
                cout<< "the array is:\n";
                mylist.display();
                cout << "pushback 2\nthe array is:\n";
                mylist.pushback(2);
                mylist.display();
                cout << "pushfront 0\nthe array is:\n";
                mylist.pushfront(0);
                mylist.display();
                cout << "popfront\nthe array is:\n";
                mylist.popfront();
                mylist.display();
                cout << "popback\nthe array is:\n";
                mylist.popback();
                mylist.display();
                cout << "the array size was initialized as 20, the head and rear occur two position,we can mostly store 18 numbers without allocating\n";
                cout << "the array is\n";
                mylist.pushback(2);
                mylist.pushback(3);
                mylist.pushback(4);
                mylist.pushback(5);
                mylist.pushback(6);
                mylist.pushback(7);
                mylist.pushback(8);
                mylist.pushback(9);
                mylist.pushback(10);
                mylist.pushback(11);
                mylist.pushback(12);
                mylist.pushback(13);
                mylist.pushback(14);
                mylist.pushback(15);
                mylist.pushback(16);
                mylist.pushback(17);

                mylist.display();
                cout << "the size of array is "<<mylist.getmaxsize()<<"\n";
                cout << "push one more element,it reaches 18 numbers and it should allocate for next number\n";
                mylist.pushback(18);
                cout << "the array is\n";
                mylist.display();
                cout << "the size of array is "<<mylist.getmaxsize()<<"\n";
                cout << "the allocate function works well,now let's test deallocate function while numitems+2<maxsize/4 && maxsize>20 as we set minisize as 20";
                cout << "\nwe push 157 numbers in first\n";
                for(int i=19;i <= 157;i++)
                {
                    mylist.pushback(i);
                }
                cout << "the array is\n";
                mylist.display();
                cout << "now the numitems and arrysize are "<<mylist.getlength()<<" and "<<mylist.getmaxsize()<<"\n";
                cout << "then, we pop 118 numbers\n";
                for(int j=0;j<118;j++)
                {
                    mylist.popback();
                }
                cout << "the array is\n";
                mylist.display();
                cout << "now the numitems and arrysize are "<<mylist.getlength()<<" and "<<mylist.getmaxsize()<<"\n";
                cout << "then we pop a number to leave 38 numbers. as the head and hear occurs two position, it will be just maxsize/4 items and should be deallocated\n";
                cout << "let's try it\n";
                mylist.popback();
                cout << "the array is\n";
                mylist.display();
                cout << "now the numitems and arrysize are "<<mylist.getlength()<<" and "<<mylist.getmaxsize()<<"\n";
                cout << "success!\n\n";
                cout << "unsuccessful case:\n";
                cout << "when the array is empty but we still try to pop a number,it should print error\n";
                cout << "for example:\n";
                cout << "we left one numbers in the array first\n";
                cout << "the array is\n";
                for(int k=0;k<36;k++)
                {
                    mylist.popback();
                }
                mylist.display();
                cout << "then we pop one number\nthe array is\n";
                mylist.popback();
                mylist.display();
                cout << "pop another\nthe array is\nacctually nothing here\n";
                mylist.popback();
                mylist.display();
                cout << "now, pop the empty array to see what will happen\n";
                cout << "the output is:\n";
                mylist.popback();
                cout << "in this case, we can't pop!";
                break;
            }
        default:
            break;
        }
    } 
    while (op != 0 && op != 6);
    return 0;
}