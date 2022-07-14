#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
       PNODE Head;

    public:
       DoublyLL();
       ~DoublyLL();
       void InsertFirst(int);
       void InsertLast(int);
       void InsertAtPosition(int,int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPosition(int pos);
       void Display();
       int Count();
};

DoublyLL:: DoublyLL()
{
    Head = NULL;
}

DoublyLL:: ~DoublyLL()
{
    PNODE temp = Head;

    while(Head != NULL)
    {
        Head = Head -> next;
        delete temp;
        temp = Head;
    }
}

void DoublyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

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

void DoublyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL,temp = Head;

    newn = new NODE;

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

void DoublyLL:: InsertAtPosition(int iNo,int pos)
{
    PNODE newn = NULL,temp = Head;

    newn = new NODE;

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

void DoublyLL::DeleteFirst()
{
    PNODE temp = Head;
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

void DoublyLL::DeleteLast()
{
    PNODE temp = Head;
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

void DoublyLL:: DeleteAtPosition(int pos)
{
    PNODE tempdelete = NULL,temp = Head;

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

void DoublyLL::Display()
{
    PNODE Temp = Head;
    while(Temp != NULL)
    {
        cout<<Temp -> data<<" -> ";
        Temp = Temp -> next;
    }
    cout<<"NULL\n";
}


int DoublyLL::Count()
{
    PNODE Temp = Head;
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
    DoublyLL obj1;
    
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

    DoublyLL obj2;
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




