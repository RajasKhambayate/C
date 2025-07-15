//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:  Queue is a linear data structure that follows the First In First Out (FIFO)       //
//principle. This program demonstrates the implementation of a simple Queue .                     //
//================================================================================================//
//Language: C                                                                                     //
//Compiler : GNU GCC                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 02th April 2025                                                                           //
//Day: Wednesday                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<stdio.h>// For printf() and scanf() Functions, etc
#include<stdlib.h>// For malloc() Function
#include<stdbool.h>// For boolean data type
#include<string.h>// For string functions

//2===============================================================================================//





//3===============================================================================================//

struct sNode//Structure declaration for node in Queue
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the linked list
};//sNODE, *PsNODE, **PPsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node
typedef struct sNode ** PPsNODE;//Pointer to the pointer of the structure node

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
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the queue is empty, update the first pointer with the address of the                      //
//   new node .                                                                                   //
//4. If the queue contains at least one node, traverse till the last node and                     //
//   update the Next pointer of the last node with the address of the new node.                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Enqueue(PPsNODE pHead,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(*pHead == NULL)//If queue is empty
    {
        *pHead = PsNewNode;
    }
    else//If queue contains atleast one node
    {
        PsNODE ptemp = *pHead;

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
    }

    printf("Node with data %d inserted at the end of the Queue\n",iNo);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Dequeue() Function: Deletes a node from beginning of the Queue .                                //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the queue is empty, return .                                                              //
//2. If the queue contains at least one node, store the address of the first node in a            //
//   temporary pointer and update the first pointer with the Next pointer of the first node and   //
//   free the memory of the temporary pointer.                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Dequeue(PPsNODE pHead)
{
    if(*pHead == NULL)//If queue is empty
    {
        printf("Queue is empty\n");
        return;
    }
    else//If queue contains atleast one node
    {
        PsNODE ptemp = *pHead;

        *pHead = ptemp -> pNext;

        printf("Node with data %d deleted from the beginning of the queue\n",ptemp -> iData);

        free(ptemp);
        ptemp = NULL;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Display() Function: Displays the entire queue .                                                 //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and display the data of each node.               //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PsNODE pHead)
{
    printf("Elements from linked list are : \n\n");

    while(pHead != NULL)
    {
        printf("| %d |\n",pHead -> iData);
        pHead = pHead -> pNext;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the Queue .                                          //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the linked list .                                                              //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Initialize a counter variable to 0.                                                          //
//2. Traverse the queue till the last node and increment the counter variable by 1 for each       //
//   node.                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PsNODE pHead)
{
    if(pHead == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }

    int iSize  = 0;

    while(pHead != NULL)
    {
        iSize++;
        pHead = pHead -> pNext;
    }

    return iSize;
}

//4===============================================================================================//





//5===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of Queue .                                             //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm: None                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Manual()
{
    printf("::::MANUAL FOR RAJAS's QUEUE APPLICATION::::\n\n\n");

    printf("INSERTION\n");
    printf("For Enqueuing data at LAST position       : press A\n\n");

    printf("DELETION\n");
    printf("For Dequeuing data from FIRST position    : press B\n\n");

    printf("COUNT\n");
    printf("To Count no. of nodes in Queue            : press H\n\n");

    printf("DISPLAY\n");
    printf("To View data in Queue                     : press G\n\n");

    printf("MANUAL\n");
    printf("For Manual                                : press M\n\n");

    printf("EXIT\n");
    printf("To exit the Queue App                     : press Z\n\n");
}


int main()
{
    PsNODE pHead1 = NULL;

    int iNo = 0;
    int iRet = 0;

    char cChoiceFunction = '\0';


    printf("Welcome to Rajas's Application of Queue\n\n");

    while(1)
    {
        printf("====================================================================================================\n");
        printf("M : For Manual\n");
        printf("Z : For Exiting the Queue Application\n");
        printf("Enter the function to be operation : ");
        scanf("%s", &cChoiceFunction);

        switch(cChoiceFunction)
        {
            case 'A':
            case 'a':
                printf("Enter the number to be inserted in Queue : ");
                scanf("%d",&iNo);
                Enqueue(&pHead1,iNo);
                break;
            case 'B':
            case 'b':
                Dequeue(&pHead1);
                break;
            case 'H':
            case 'h':
                iRet = Count(pHead1);
                printf("Number of nodes in the queue are : %d\n",iRet);
                break;
            case 'G':
            case 'g':
                Display(pHead1);
                break;
            case 'M':
            case 'm':
                Manual();
                break;
            case 'Z':
            case 'z':
                printf("Exiting the RAJAS's QUEUE application\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

//5===============================================================================================//