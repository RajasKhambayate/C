//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:  Stack is a linear data structure that follows the First In First Out (LIFO)       //
//principle. This program demonstrates the implementation of a simple Stack .                     //
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

//2===============================================================================================//





//3===============================================================================================//

struct sNode//Structure declaration for node in Stack
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the Stack
};//sNODE, *PsNODE, **PPsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node
typedef struct sNode ** PPsNODE;//Pointer to the pointer of the structure node

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
//1. PPsNODE : Address of the first pointer of the stack .                                        //
//2. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the stack .                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Push(PPsNODE pHead,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(*pHead == NULL)//If stack is empty
    {
        *pHead = PsNewNode;
    }
    else//If stack contains atleast one node
    {
        PsNODE ptemp = *pHead;

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Pop() Function: Deletes a node from top of the Stack .                                          //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the Stack .                                        //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the Stack .                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Pop(PPsNODE pHead)
{
    int iDeleted = 0;

    if((*pHead) -> pNext == NULL)//If stack is empty
    {
        iDeleted = (*pHead) -> iData;
        free(*pHead);
        *pHead = NULL;
    }
    else//If stack contains atleast one node
    {
        PsNODE ptemp = *pHead;
        *pHead = ptemp -> pNext;

        iDeleted = ptemp -> iData;

        free(ptemp);
        ptemp = NULL;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Display() Function: Displays the entire stack .                                                 //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the stack .                                         //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PsNODE pHead)
{
    printf("Elements from stack are : \n\n");

    while(pHead != NULL)
    {
        printf("| %d |\n",pHead -> iData);
        pHead = pHead -> pNext;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the Stack .                                          //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the stack .                                         //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the stack .                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PsNODE pHead)
{
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
//Manual() Function: A guide for the usage of Stack .                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Manual()
{
    printf("::::MANUAL FOR RAJAS's STACK APPLICATION::::\n\n\n");

    printf("INSERTION\n");
    printf("For Pushing data onto the Stack            : press A\n\n");

    printf("DELETION\n");
    printf("For Popping data from the Stack            : press B\n\n");

    printf("COUNT\n");
    printf("To Count no. of nodes in Stack             : press H\n\n");

    printf("DISPLAY\n");
    printf("To View data in Stack                      : press G\n\n");

    printf("MANUAL\n");
    printf("For Manual                                 : press M\n\n");

    printf("EXIT\n");
    printf("To exit the Stack App                      : press Z\n\n");
}


int main()
{
    PsNODE pHead1 = NULL;

    int iNo = 0;
    int iRet = 0;

    char cChoiceFunction = '\0';


    printf("Welcome to Rajas's Application of Stack\n\n");

    while(1)
    {
        printf("====================================================================================================\n");
        printf("M : For Manual\n");
        printf("Z : For Exiting the Stack Application\n");
        printf("Enter the function to be operation : ");
        scanf("%s", &cChoiceFunction);

        switch(cChoiceFunction)
        {
            case 'A':
            case 'a':
                printf("Enter the number to be inserted in Stack : ");
                scanf("%d",&iNo);

                Push(&pHead1,iNo);
                printf("Node with data %d inserted at the top of the stack\n", iNo);

                break;
            case 'B':
            case 'b':
                Pop(&pHead1);
                break;
            case 'H':
            case 'h':
                if(Count(pHead1) != 0)
                {
                    iRet = Pop(&pHead1);
                    printf("deleted data from top position is : %d\n",iRet);
                }
                else
                {
                    printf("The stack is empty\n");
                }

                break;
            case 'G':
            case 'g':
                if((iRet = Count(pHead1)) != 0)
                {
                    Display(pHead1);
                }
                else
                {
                    printf("The stack is empty\n");
                }

                break;
            case 'M':
            case 'm':
                Manual();

                break;
            case 'Z':
            case 'z':
                printf("Exiting the RAJAS's STACK application\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

//5===============================================================================================//