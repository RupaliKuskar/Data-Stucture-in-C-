#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;

    public:
        DoublyCLL();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int Count();
        void Display();
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
}

template <class T>
void DoublyCLL<T>::InsertFirst(int iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;
}

template <class T>
void DoublyCLL<T>::InsertLast(int iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail -> next = Head;
        newn -> prev = Tail;   

        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;   
}

template <class T>
void DoublyCLL<T>::InsertAtPos(int iNo, int ipos)
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
            newn -> prev = NULL;

            struct node<T> *temp = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
    }
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
            return;
    }
    else if(Head -> next == NULL)
    {
            delete Head;
            Head = NULL;
            Tail = NULL;
    }
    else
    {
            Head = Head->next;
            delete Tail->next;          // delete Head->prev;
    }

    Tail->next = Head;
    Head->prev = Tail;

}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
            return;
    }
    else if(Head->next == NULL)
    {
            delete Tail;
            Head = NULL;
            Tail = NULL;
    }
    else
    {
            Tail = Tail->prev;
            delete Tail->next;          // delete Head->prev;
    }

    Tail->next = Head;
    Head->prev = Tail;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Count()))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Count())
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;

        for(int i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

    }
}

template <class T>
void DoublyCLL<T>::Display()
{
    int i = 0;
    struct node<T> *temp = Head;

    for(i = 1; i<= Count(); i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";

}

template <class T>
int DoublyCLL<T>::Count()
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
    DoublyCLL <int> obj1;
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertFirst(101);
    obj1.InsertFirst(111);

    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertAtPos(75,4);
    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    DoublyCLL<float> obj2;
    obj2.InsertFirst(501.11);
    obj2.InsertFirst(511.11);
    obj2.InsertFirst(521.11);

    obj2.Display();

    obj2.InsertLast(551.11);
    obj2.InsertAtPos(601.11,3);

    obj2.Display();

    cout<<"\nNumber of nodes : "<<obj2.Count()<<"\n";

}


