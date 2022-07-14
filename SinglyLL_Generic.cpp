#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

template <class T>
struct node
{
    T Data;
    struct node* Next;
};

template <class T>
class Singly_linkedList
{
    public:
        struct node<T> *Head;

    public:
        Singly_linkedList();
        BOOL InsertFirst ( T );
        BOOL InsertLast ( T );
        BOOL InsertAtPosition ( T, int );
        inline void Display( );
        inline int Count( );
        BOOL DeleteFirst( );
        BOOL DeleteAtPosition(int);
        BOOL DeleteLast( );
};
template <class T>
Singly_linkedList<T> ::Singly_linkedList ( )
{
    Head = NULL;
}

template <class T>
BOOL Singly_linkedList<T>::InsertFirst( T no )
{
    struct node<T> *newn = NULL;

    newn = new node<T>;
    if (newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;
    newn->Data = no;

    if (Head == NULL)
    {
        Head = newn;
    }
    else 
    {
        newn -> Next = Head;
        Head = newn;
    }
    return TRUE;
}

template <class T>
BOOL Singly_linkedList<T>::InsertLast ( T no)
{
    struct node<T> *newn = NULL; 
    struct node<T> *temp = Head;
    newn = new node<T>;

    if (newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;
    newn->Data = no;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
    }

    return TRUE;
}

template <class T>
BOOL Singly_linkedList<T>::InsertAtPosition( T no,int pos)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }

    if( pos == 1 )
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count( )) + 1)
    {
        return(InsertLast(no));
    }
    else
    {
        struct node<T> *newn = NULL;
        struct node<T> *temp = Head;

        newn = new node<T>;
        if (newn == NULL)
        {
            return FALSE;
        }

        newn -> Next = NULL;
        newn -> Data = no;

        for(int i = 1; i <= (pos-2); i++)
        {
             temp = temp -> Next;
        }

        newn -> Next = temp -> Next;
        temp -> Next = newn;
    }
    return TRUE;
}

template <class T>
BOOL Singly_linkedList<T>::DeleteFirst()
{ 
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> Next;
        free(temp);
    }
    return TRUE;
}

template <class T>
BOOL Singly_linkedList<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    else if(Head->Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp1 = Head, *temp2 = NULL;

        while(temp1 -> Next -> Next != NULL)
        {
            temp1 = temp1 -> Next;
        }

        temp2 = temp1 -> Next;
        temp1->Next = NULL;
        free(temp2);
    }
    return TRUE;
}

template <class T>
BOOL Singly_linkedList<T>::DeleteAtPosition( int pos )
{
    if((Head == NULL) || (pos > Count()) || (pos <= 0))
    {
        return FALSE;
    }
    else if( pos == 1 )
    {
        DeleteFirst();
    }
    else if(pos == (Count( )))
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp1 = Head, *temp2 = NULL;

        for(int i = 1; i<= (pos-2); i++)
        {
            temp1 = temp1 -> Next;
            ++i;
        }

        temp2 = temp1 -> Next;
        temp1->Next = temp2->Next;

        delete temp2;
    }
    return TRUE;
}

template <class T>
void Singly_linkedList<T>::Display()
{
    struct node<T> *Temp = Head;
    while(Temp != NULL)
    {
        cout<<Temp -> Data<<" -> ";
        Temp = Temp -> Next;
    }
    cout<<"NULL\n";
}

template <class T>
int Singly_linkedList<T>::Count()
{
    struct node<T> *Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp -> Next;
    }
    return iCnt;
}

int main()
{
    Singly_linkedList <int>obj1;
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertFirst(101);
    obj1.InsertFirst(111);

    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertAtPosition(75,4);
    obj1.Display();

    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    Singly_linkedList <float>obj2;
    obj2.InsertFirst(501);
    obj2.InsertFirst(511);
    obj2.InsertFirst(521);

    obj2.Display();

    obj2.InsertLast(551);
    obj2.InsertAtPosition(601,3);

    obj2.Display();

    cout<<"\nNumber of nodes : "<<obj2.Count()<<"\n";

    return 0;
} 