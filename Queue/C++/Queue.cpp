//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:  Queue is a linear data structure that follows the First In First Out (FIFO)       //
//principle. This program demonstrates the implementation of a simple Queue .                     //
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


class Queue
{
    private:
        PsNODE pHead;//Pointer to the first node of the linked list
        int iCountNode;//Counter for the number of nodes in the linked list

    public:
        Queue();
        ~Queue();

        //Insertion functions
        void Enqueue(int);

        //Deletion functions
        int Dequeue();

        //Traversal functions
        int Count();
        void Display();

        //Manual
        void Manual();
};


Queue::Queue()
{
    pHead = NULL;
    iCountNode = 0;
}


Queue::~Queue()
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
//                                             Queue                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions:                                                                                      //
//================================================================================================//
//Insertion:                                                                                      //
//1. Enqueue() : Inserts a new node at the end of the queue .                                     //
//================================================================================================//
//Deletion:                                                                                       //
//2. Dequeue() : Deletes the first node of the queue .                                            //
//================================================================================================//
//Traversal:                                                                                      //
//3. Display() : Displays the contents of the queue .                                             //
//4. Count() : Counts the number of nodes in the queue .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//Enqueue() Function: Inserts a new node at the end of the Queue .                                //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the queue .                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queue::Enqueue(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if((iCountNode == 0) && (pHead == NULL))//If queue is empty
    {
        pHead = PsNewNode;
    }
    else//If queue contains atleast one node
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
//Dequeue() Function: Deletes a node from beginning of the Queue .                                //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the queue .                                           //
//2. int : variable to return the deleted data                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Queue::Dequeue()
{
    int iDeleted = 0;

    if(pHead -> pNext == NULL)
    {
        iDeleted = pHead -> iData;
        delete pHead;
        pHead = NULL;
    }
    else//If queue contains atleast one node
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
//Display() Function: Displays the entire queue .                                                 //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queue::Display()
{
    cout<<"Elements from queue are : "<<endl<<endl;

    while(pHead != NULL)
    {
        cout<<"| "<<pHead -> iData<<" |"<<endl;
        pHead = pHead -> pNext;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the Queue .                                          //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the queue .                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Queue::Count()
{
    return iCountNode;
}

//4===============================================================================================//





//5===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of Queue .                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Queue::Manual()
{
    cout<<"::::MANUAL FOR RAJAS's QUEUE APPLICATION::::"<<endl<<endl<<endl;

    cout<<"INSERTION"<<endl;
    cout<<"For Enqueuing data at LAST position       : press A"<<endl<<endl;

    cout<<"DELETION"<<endl;
    cout<<"For Dequeuing data from FIRST position    : press B"<<endl<<endl;

    cout<<"COUNT"<<endl;
    cout<<"To Count no. of nodes in Queue            : press H"<<endl<<endl;

    cout<<"DISPLAY"<<endl;
    cout<<"To View data in Queue                     : press G"<<endl<<endl;

    cout<<"MANUAL"<<endl;
    cout<<"For Manual                                : press M"<<endl<<endl;

    cout<<"EXIT"<<endl;
    cout<<"To exit the Queue App                     : press Z"<<endl<<endl;
}


int main()
{
    Queue Queue;

    int iNo = 0;
    int iRet = 0;

    char cChoiceFunction = '\0';


    cout<<"Welcome to Rajas's Application of Queue"<<endl<<endl;

    while(1)
    {
        cout<<"===================================================================================================="<<endl;
        cout<<"M : For Manual"<<endl;
        cout<<"Z : For Exiting the Queue Application"<<endl;
        cout<<"Enter the function to be operation : ";
        cin>>cChoiceFunction;

        switch(cChoiceFunction)
        {
            case 'A':
            case 'a':
                cout<<"Enter the number to be inserted in Queue : ";
                scanf("%d",&iNo);

                Queue.Enqueue(iNo);
                cout<<"Node with data "<<iNo<<" inserted at the end of the queue"<<endl;

                break;
            case 'B':
            case 'b':
                if(Queue.Count() != 0)
                {
                    iRet = Queue.Dequeue();
                    cout<<"deleted data from last position is : "<<iRet<<endl;
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }

                break;
            case 'H':
            case 'h':
                iRet = Queue.Count();
                cout<<"Number of nodes in the queue are : "<<iRet<<endl;
                break;
            case 'G':
            case 'g':
                if((iRet = Queue.Count()) != 0)
                {
                    Queue.Display();
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }

                break;
            case 'M':
            case 'm':
                Queue.Manual();

                break;
            case 'Z':
            case 'z':
                cout<<"Exiting the RAJAS's QUEUE application"<<endl;

                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}

//5===============================================================================================//