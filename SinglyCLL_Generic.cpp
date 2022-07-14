#include<iostream>
using namespace std;

template <class T>
struct node
{
    int data;
    struct node *next;
};

template <class T>
class SinglyCLL
{
    private:
       struct node<T> *Head;
       struct node<T> *Tail;

    public:
       SinglyCLL();
       ~SinglyCLL();
       void InsertFirst(T);
       void InsertLast(T);
       void InsertAtPos(T,int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int);
       void Display();
       int Count();
};

template <class T>
SinglyCLL<T>:: SinglyCLL()
{
    Head = NULL;
}

template <class T>
SinglyCLL<T>:: ~SinglyCLL()
{
    struct node<T> *temp = Head;
    while(Head != NULL)
    {
        Head = Head -> next;
        delete temp;
        temp = Head;
    }
}

template <class T>
void SinglyCLL<T>:: InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL || Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail -> next = Head;
}

template <class T>
void SinglyCLL<T>:: InsertLast(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn -> data = iNo;
    newn -> next = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;      
    }
    else
    {
        Tail -> next = newn;
        Tail = newn;
    }
    Tail -> next = Head;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T iNo, int ipos)
{
    int iSize = Count();

    if((ipos < 1) || (ipos > iSize+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(iNo);
    }
    else if(ipos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
            struct node<T> *newn = NULL;

            newn = new node<T>;

            newn->data = iNo;
            newn->next = NULL;

            struct node<T> *temp = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp -> next;
            temp->next = newn;
    }
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head -> next;
        delete Tail->next;

        Tail -> next = Head;
    }
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct node<T> *temp = Head;
        while(temp -> next != Tail)
        {
            temp =temp -> next;
        }
        delete Tail;
        Tail = temp;

        Tail -> next = Head;
    }
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int iSize = Count();

    if((ipos < 1) || (ipos > iSize))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
            struct node<T> *temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node<T> *temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
    }
}

template <class T>
void SinglyCLL<T>:: Display()
{
    struct node<T> *temp = Head;

    do
    {
        cout<<"|"<<temp -> data<<"|->";
        temp = temp -> next;        
    }while(temp != Head);

    cout<<endl;
}

template <class T>
int SinglyCLL<T>::Count()
{
    int iCnt = 0;
    struct node<T> *temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Head);

    return iCnt;
     
}

int main()
{
    SinglyCLL<int> obj1;
    int iRet = 0;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj1.InsertAtPos(75,4);

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj1.DeleteAtPos(4);

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    SinglyCLL<float> obj2;
    int fRet = 0;

    obj2.InsertFirst(51);
    obj2.InsertFirst(21);
    obj2.InsertFirst(11);
    obj2.InsertLast(101);
    obj2.InsertLast(111);

    obj2.Display();
    fRet = obj2.Count();

    cout<<"Number of nodes are : "<<fRet<<endl;

    obj2.InsertAtPos(75,4);

    obj2.Display();
    iRet = obj2.Count();

    cout<<"Number of nodes are : "<<fRet<<endl;

    obj2.DeleteAtPos(4);

    obj2.Display();
    iRet = obj2.Count();

    cout<<"Number of nodes are : "<<fRet<<endl;


    return 0;
}