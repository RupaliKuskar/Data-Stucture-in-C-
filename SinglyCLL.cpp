#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCLL
{
    private:
       PNODE Head;
       PNODE Tail;

    public:
       SinglyCLL();
       ~SinglyCLL();
       void InsertFirst(int);
       void InsertLast(int);
       void InsertAtPos(int,int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int);
       void Display();
       int Count();
};

SinglyCLL:: SinglyCLL()
{
    Head = NULL;
}

SinglyCLL:: ~SinglyCLL()
{
    PNODE temp = Head;
    while(Head != NULL)
    {
        Head = Head -> next;
        delete temp;
        temp = Head;
    }
}

void SinglyCLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

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

void SinglyCLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

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

void SinglyCLL::InsertAtPos(int iNo, int ipos)
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
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = iNo;
            newn->next = NULL;

            PNODE temp = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp -> next;
            temp->next = newn;
    }
}

void SinglyCLL::DeleteFirst()
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

void SinglyCLL::DeleteLast()
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
        PNODE temp = Head;
        while(temp -> next != Tail)
        {
            temp =temp -> next;
        }
        delete Tail;
        Tail = temp;

        Tail -> next = Head;
    }
}

void SinglyCLL::DeleteAtPos(int ipos)
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
            PNODE temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            PNODE temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
    }
}

void SinglyCLL:: Display()
{
    PNODE temp = Head;

    do
    {
        cout<<"|"<<temp -> data<<"|->";
        temp = temp -> next;        
    }while(temp != Head);

    cout<<endl;
}

int SinglyCLL::Count()
{
    int iCnt = 0;
    PNODE temp = Head;

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
    SinglyCLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;


    return 0;
}