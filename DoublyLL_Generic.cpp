#include<iostream>
using namespace std;

template <class T>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLL
{
    private:
       struct node<T> *Head;

    public:
       DoublyLL();
       ~DoublyLL();
       void InsertFirst(T);
       void InsertLast(T);
       void InsertAtPosition(T,int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPosition(int);
       void Display();
       int Count();
};

template <class T>
DoublyLL<T>:: DoublyLL()
{
    Head = NULL;
}

template <class T>
DoublyLL<T>:: ~DoublyLL()
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
void DoublyLL<T>:: InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head-> prev = newn;
        Head = newn;
    }
}

template <class T>
void DoublyLL<T>:: InsertLast(T iNo)
{
    struct node<T> *newn = NULL,*temp = Head;

    newn = new node<T>;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        newn = temp-> next;
        newn->prev = temp;        
    }
}

template <class T>
void DoublyLL<T>:: InsertAtPosition(T iNo,int pos)
{
    struct node<T> *newn = NULL,*temp = Head;

    newn = new node<T>;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((pos<1) || pos > (Count()+1))
    {
        cout<<"Invalid Position"<<endl;
    }
    if(pos == 1)
    {
        return (InsertFirst(iNo));
    }
    else if(pos == (Count())+1)
    {
        return (InsertLast(iNo));
    }
    else
    {
        for(int iCnt=1;iCnt<=(pos-2);iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp->next->prev = newn;
        temp -> next = newn;
        temp -> prev = temp;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;
    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head -> next;
        Head -> prev = NULL;
        free(temp);
    }
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> *temp = Head;
    if(Head == NULL)
    {
        return;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->prev-> next = NULL;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>:: DeleteAtPosition(int pos)
{
    struct node<T> *tempdelete = NULL,*temp = Head;

    if((pos<1) || pos > (Count()))
    {
        cout<<"Invalid Position"<<endl;
    }
    if(pos == 1)
    {
        return (DeleteFirst());
    }
    else if(pos == (Count()))
    {
        return (DeleteLast());
    }
    else
    {
        for(int iCnt=1;iCnt<=(pos-2);iCnt++)
        {
            temp = temp -> next;
        }
        temp->next = temp -> next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> *Temp = Head;
    while(Temp != NULL)
    {
        cout<<Temp -> data<<" -> ";
        Temp = Temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    struct node<T> *Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp -> next;
    }
    return iCnt;
}

int main()
{
    DoublyLL <int> obj1;
    
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

    DoublyLL <float> obj2;
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




