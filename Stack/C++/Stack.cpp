//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:  Stack is a linear data structure that follows the First In First Out (LIFO)       //
//principle. This program demonstrates the implementation of a simple Stack .                     //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 18th April 2025                                                                           //
//Day: Thursday                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<iostream>
using namespace std;

//2===============================================================================================//





//3===============================================================================================//

struct sNode//Structure declaration for node in Queue
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the Queue
};//sNODE, *PsNODE, **PPsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node


class Stack
{
    private:
        PsNODE pHead;//Pointer to the first node of the linked list
        int iCountNode;//Counter for the number of nodes in the linked list

    public:
        Stack();
        ~Stack();

        //Insertion functions
        void Push(int);

        //Deletion functions
        int Pop();

        //Traversal functions
        int Count();
        void Display();

        //Manual
        void Manual();
};


Stack::Stack()
{
    pHead = NULL;
    iCountNode = 0;
}


Stack::~Stack()
{
    PsNODE ptemp = pHead;

    while(ptemp != NULL)
    {
        ptemp = ptemp -> pNext;
        delete pHead;
        pHead = ptemp;
    }

    pHead = NULL;
    iCountNode = 0;
}

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                             Stack                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions:                                                                                      //
//================================================================================================//
//Insertion:                                                                                      //
//1. Push() : Inserts a new node at the top of the stack .                                        //
//================================================================================================//
//Deletion:                                                                                       //
//2. Pop() : Deletes the top node of the stack .                                                  //
//================================================================================================//
//Traversal:                                                                                      //
//3. Display() : Displays the contents of the stack .                                             //
//4. Count() : Counts the number of nodes in the stack .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//Push() Function: Inserts a new node at the top of the Stack .                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the stack .                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Stack::Push(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if((iCountNode == 0) && (pHead == NULL))//If stack is empty
    {
        pHead = PsNewNode;
    }
    else//If stack contains atleast one node
    {
        PsNODE ptemp = pHead;

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
    }

    iCountNode++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Pop() Function: Deletes a node from top of the Stack .                                          //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the stack .                                           //
//2. int : Data of the deleted node .                                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Stack::Pop()
{
    int iDeleted = 0;

    if(pHead -> pNext == NULL)
    {
        iDeleted = pHead -> iData;
        delete pHead;
        pHead = NULL;
    }
    else//If stack contains atleast one node
    {
        PsNODE ptemp = pHead;
        pHead = ptemp -> pNext;

        iDeleted = ptemp -> iData;

        delete ptemp;
        ptemp = NULL;
    }

    iCountNode--;

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Display() Function: Displays the entire stack .                                                 //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Stack::Display()
{
    cout<<"Elements from stack are : "<<endl<<endl;

    while(pHead != NULL)
    {
        cout<<"| "<<pHead -> iData<<" |"<<endl;
        pHead = pHead -> pNext;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the Stack .                                          //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the stack .                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Stack::Count()
{
    return iCountNode;
}

//4===============================================================================================//





//5===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of Stack .                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Stack::Manual()
{
    cout<<"::::MANUAL FOR RAJAS's STACK APPLICATION::::"<<endl<<endl<<endl;

    cout<<"INSERTION"<<endl;
    cout<<"For Pushing data at LAST position       : press A"<<endl<<endl;

    cout<<"DELETION"<<endl;
    cout<<"For Popping data from FIRST position    : press B"<<endl<<endl;

    cout<<"COUNT"<<endl;
    cout<<"To Count no. of nodes in Stack          : press H"<<endl<<endl;

    cout<<"DISPLAY"<<endl;
    cout<<"To View data in Stack                   : press G"<<endl<<endl;

    cout<<"MANUAL"<<endl;
    cout<<"For Manual                              : press M"<<endl<<endl;

    cout<<"EXIT"<<endl;
    cout<<"To exit the Stack App                   : press Z"<<endl<<endl;
}


int main()
{
    Stack Stack;

    int iNo = 0;
    int iRet = 0;

    char cChoiceFunction = '\0';


    cout<<"Welcome to Rajas's Application of Stack"<<endl<<endl;

    while(1)
    {
        cout<<"===================================================================================================="<<endl;
        cout<<"M : For Manual"<<endl;
        cout<<"Z : For Exiting the Stack Application"<<endl;
        cout<<"Enter the function to be operation : ";
        cin>>cChoiceFunction;

        switch(cChoiceFunction)
        {
            case 'A':
            case 'a':
                cout<<"Enter the number to be inserted in Stack : ";
                cin>>iNo;

                Stack.Push(iNo);
                cout<<"Node with data "<<iNo<<" inserted at the top of the stack"<<endl;

                break;
            case 'B':
            case 'b':
                if(Stack.Count() != 0)
                {
                    iRet = Stack.Pop();
                    cout<<"deleted data from top position is : "<<iRet<<endl;
                }
                else
                {
                    cout<<"The stack is empty"<<endl;
                }

                break;
            case 'H':
            case 'h':
                iRet = Stack.Count();
                cout<<"Number of nodes in the stack are : "<<iRet<<endl;

                break;
            case 'G':
            case 'g':
                if((iRet = Stack.Count()) != 0)
                {
                    Stack.Display();
                }
                else
                {
                    cout<<"The stack is empty"<<endl;
                }

                break;
            case 'M':
            case 'm':
                Stack.Manual();

                break;
            case 'Z':
            case 'z':
                cout<<"Exiting the RAJAS's STACK application"<<endl;

                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}

//5===============================================================================================//